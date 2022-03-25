use core::cell::RefCell;

pub mod clock {
    use embedded_sdmmc::{TimeSource, Timestamp};

    //Keeps tracks of when files are made
    pub struct FakeClock;

    impl TimeSource for FakeClock {
        fn get_timestamp(&self) -> embedded_sdmmc::Timestamp {
            Timestamp {
                year_since_1970: 30,
                zero_indexed_month: 2,
                zero_indexed_day: 4,
                hours: 8,
                minutes: 31,
                seconds: 2,
            }
        }
    }
}

#[cfg(no_std)]
pub mod sd_trait {
    use sdfile::sd::{
        close_directory, close_file, get_volume, open_file, read_file, root_dir, write_into_file,
    };

    use sdfile::{SdFile, SdMmcConfig};

    use core::result::Result;

    impl<'a, D: embedded_sdmmc::BlockDevice, T: embedded_sdmmc::TimeSource> File for SdFile<'a, D, T> {
        fn write(&mut self, buffer: &[u8]) -> Result<usize, ()> {
            let mut controller = self.controller.borrow_mut();
            let mut volume = get_volume(&mut controller);

            Ok(write_into_file(
                &mut controller,
                &mut self.file,
                &mut volume,
                buffer,
            ))
        }

        fn read(&mut self, buffer: &mut [u8]) -> Result<usize, ()> {
            let mut controller = self.controller.borrow_mut();
            let mut volume = get_volume(&mut controller);

            Ok(read_file(
                &mut controller,
                &mut self.file,
                &mut volume,
                buffer,
            ))
        }
    }

    impl<'a, D: embedded_sdmmc::BlockDevice, S: embedded_sdmmc::TimeSource> FileInterface
        for SdMmcConfig<'a, D, S>
    {
        type FileType = SdFile<'a, D, S>;

        fn open<T: AsRef<str>>(&self, path: T, mode: FileMode) -> Result<Self::FileType, ()> {
            let mut controller = self.controller.borrow_mut();
            let mut volume = get_volume(&mut controller);
            let directory = root_dir(&mut controller, &volume);

            let file_mode;
            match mode {
                FileMode::ReadOnly => {
                    file_mode = embedded_sdmmc::Mode::ReadOnly;
                }
                FileMode::ReadWriteAppend => file_mode = embedded_sdmmc::Mode::ReadWriteAppend,
                FileMode::ReadWriteTruncate => file_mode = embedded_sdmmc::Mode::ReadWriteTruncate,
                FileMode::ReadWriteCreate => file_mode = embedded_sdmmc::Mode::ReadWriteCreate,
                FileMode::ReadWriteCreateOrAppend => {
                    file_mode = embedded_sdmmc::Mode::ReadWriteCreateOrAppend
                }
                FileMode::ReadWriteCreateOrTruncate => {
                    file_mode = embedded_sdmmc::Mode::ReadWriteCreateOrTruncate
                }
            };

            let file = open_file(
                &mut controller,
                &directory,
                &mut volume,
                path.as_ref(),
                file_mode,
            );

            Ok(SdFile::new(&self.controller, file))
        }

        fn close(file: Self::FileType) -> Result<(), ()> {
            let mut controller = file.controller.borrow_mut();
            let mut volume = get_volume(&mut controller);
            let directory = root_dir(&mut controller, &mut volume);

            close_file(&mut controller, file.file, &mut volume);

            Ok(close_directory(&mut controller, directory, &mut volume))
        }
    }
}

pub struct SdFile<'a, D, T>
where
    D: embedded_sdmmc::BlockDevice,
    T: embedded_sdmmc::TimeSource,
{
    pub controller: &'a RefCell<embedded_sdmmc::Controller<D, T>>,
    pub file: embedded_sdmmc::File,
}

impl<'a, D: embedded_sdmmc::BlockDevice, T: embedded_sdmmc::TimeSource> SdFile<'a, D, T> {
    pub fn new(
        controller: &'a RefCell<embedded_sdmmc::Controller<D, T>>,
        file: embedded_sdmmc::File,
    ) -> Self {
        SdFile { controller, file }
    }
}

pub struct SdMmcConfig<'a, D, T>
where
    D: embedded_sdmmc::BlockDevice,
    T: embedded_sdmmc::TimeSource,
{
    pub controller: &'a RefCell<embedded_sdmmc::Controller<D, T>>,
}

pub mod sd {

    use core::fmt::Debug;
    use embedded_sdmmc::BlockDevice;
    use embedded_sdmmc::Directory;
    use embedded_sdmmc::TimeSource;
    use embedded_sdmmc::Volume;
    use embedded_sdmmc::VolumeIdx;

    //Make the sdmmc_spi
    pub fn make_sdmmcspi<SPI, CS>(spi: SPI, cs: CS) -> embedded_sdmmc::SdMmcSpi<SPI, CS>
    where
        SPI: embedded_hal::spi::FullDuplex<u8>,
        CS: embedded_hal::digital::v2::OutputPin,
        <SPI as embedded_hal::spi::FullDuplex<u8>>::Error: Debug,
    {
        embedded_sdmmc::SdMmcSpi::new(spi, cs)
    }

    //returns a controller to handle
    //all file handling.
    pub fn controller<D, T>(block_device: D, fake_clock: T) -> embedded_sdmmc::Controller<D, T>
    where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        embedded_sdmmc::Controller::new(block_device, fake_clock)
    }

    //Returns the volume of the controller
    pub fn get_volume<D, T>(controller: &mut embedded_sdmmc::Controller<D, T>) -> Volume
    where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        //Usually is always 0
        controller.get_volume(VolumeIdx(0)).unwrap()
    }

    //Open the root directory of the controller
    pub fn root_dir<D, T>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        volume: &Volume,
    ) -> Directory
    where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        controller.open_root_dir(volume).unwrap()
    }

    //Open file given a name
    //inside the controller's volume and directory
    pub fn open_file<D, T, A>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        dir: &Directory,
        volume: &mut Volume,
        file_name: A,
        file_mode: embedded_sdmmc::Mode,
    ) -> embedded_sdmmc::File
    where
        D: BlockDevice,
        T: TimeSource,
        A: AsRef<str>,
        <D as BlockDevice>::Error: Debug,
    {
        controller
            .open_file_in_dir(volume, &dir, file_name.as_ref(), file_mode)
            .unwrap()
    }

    //Write into the file given
    //File must be in controller's volume.
    pub fn write_into_file<D, T>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        file: &mut embedded_sdmmc::File,
        volume: &mut Volume,
        buffer: &[u8],
    ) -> usize
    where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        controller.write(volume, file, buffer).unwrap()
    }

    //Read a file
    pub fn read_file<D, T>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        file: &mut embedded_sdmmc::File,
        volume: &mut Volume,
        buffer: &mut [u8],
    ) -> usize
    where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        controller.read(volume, file, buffer).unwrap()
    }

    //Closes the file
    //
    pub fn close_file<D, T>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        file: embedded_sdmmc::File,
        volume: &mut Volume,
    ) where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        controller.close_file(volume, file).unwrap()
    }

    //Closes the directory
    pub fn close_directory<D, T>(
        controller: &mut embedded_sdmmc::Controller<D, T>,
        directory: embedded_sdmmc::Directory,
        volume: &mut Volume,
    ) where
        D: BlockDevice,
        T: TimeSource,
        <D as BlockDevice>::Error: Debug,
    {
        controller.close_dir(volume, directory)
    }
}
