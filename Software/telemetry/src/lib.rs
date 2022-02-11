trait FileInterface {
    ///Type that needs to be specified when using the FileInterface trait.
    ///The type must also implement the trait File
    type FileType: File;

    ///This function opens a file defined by some path
    fn open<T: AsRef<str>>(path: T, mode: FileMode) -> Result<Self::FileType, ()>;

    ///Closes the current File opened.
    fn close(file: Self::FileType) -> Result<(), ()>;

    fn flash() -> Result<Self::FileType, ()>;
}

trait File {
    ///Writes a given buffer into File
    fn write(buffer: &[u8]) -> Result<(), ()>;

    ///Reads file by modifying a given buffer and writing into it.
    fn read(buffer: &mut [u8]) -> Result<(), ()>;
}

pub struct FileIO;

//impl FileInterface for FileIO {}

pub enum FileMode {
    ReadOnly,
    ReadWriteAppend,
    ReadWriteTruncate,
    ReadWriteCreate,
    ReadWriteCreateOrTruncate,
    ReadWriteCreateOrAppend,
}
