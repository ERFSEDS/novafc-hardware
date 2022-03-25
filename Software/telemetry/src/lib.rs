#![cfg_attr(not(feature = "std"), no_std)]

use core::convert::AsRef;

///The primitive function that will be used in order to open, close files
///This takes a type that Implements File
pub trait FileInterface {
    ///Type that needs to be specified when using the FileInterface trait.
    ///The type must also implement the trait File
    type FileType: File;

    ///This function opens a file defined by some path
    fn open<T: AsRef<str>>(&self, path: T, mode: FileMode) -> Result<Self::FileType, ()>;

    ///Closes the current File opened.
    fn close(file: Self::FileType) -> Result<(), ()>;
}

///Implementation of a file
///It needs to be able to write and read using a buffer
pub trait File {
    ///Writes a given buffer into File
    fn write(&mut self, buffer: &[u8]) -> Result<usize, ()>;

    ///Reads file by modifying a given buffer and writing into it.
    fn read(&mut self, buffer: &mut [u8]) -> Result<usize, ()>;
}

//pub mod std_file {
//    use crate::{File, FileInterface, FileMode};
//
//    impl File for std::fs::File {
//        ///Testing purposes
//        fn write(&mut self, buffer: &[u8]) -> Result<usize, ()> {
//            std::io::Write::write(self, buffer)
//                .map_err(|_| println!("Error at writing to file, cutie!"))
//        }
//
//        fn read(&mut self, buffer: &mut [u8]) -> Result<usize, ()> {
//            std::io::Read::read(self, buffer)
//                .map_err(|_| println!("Error at reading file, dumbass!"))
//        }
//    }
//
//    pub struct FileIO;
//
//    impl FileInterface for FileIO {
//        type FileType = std::fs::File;
//
//        fn open<T: AsRef<str>>(&self, path: T, mode: FileMode) -> Result<Self::FileType, ()> {
//            //File options
//            let mut file_options = std::fs::File::options();
//            file_options.read(true); //Default Read option is true
//
//            //Matches the way the file should be open
//            //Read-File will always be true
//            match mode {
//                FileMode::ReadWriteAppend => {
//                    file_options.write(true).append(true);
//                }
//                FileMode::ReadWriteTruncate => {
//                    file_options.write(true).truncate(true);
//                }
//                FileMode::ReadWriteCreate => {
//                    file_options.write(true).create(true);
//                }
//                FileMode::ReadWriteCreateOrTruncate => {
//                    file_options.write(true).create(true).truncate(true);
//                }
//                FileMode::ReadWriteCreateOrAppend => {
//                    file_options.write(true).create(true).append(true);
//                }
//                FileMode::ReadOnly => {}
//            }
//
//            //Return
//            file_options
//                .open(path.as_ref())
//                .map_err(|_err| println!("Stinky OH Oh!!!"))
//        }
//
//        fn close(file: Self::FileType) -> Result<(), ()> {
//            file.sync_all() //Makes sure to save data when the files closes. [Precautions]
//                .map_err(|_| println!("Caca on Closing file"))
//        }
//    }
//}

///Different modes of opening a file
///Such as reading, writing, creating etc..
pub enum FileMode {
    ReadOnly,
    ReadWriteAppend,
    ReadWriteTruncate,
    ReadWriteCreate,
    ReadWriteCreateOrTruncate,
    ReadWriteCreateOrAppend,
}
