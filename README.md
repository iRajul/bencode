# Bencode
Bencode is  is a fully featured, open source, c++ library used to encode and decode [bencode](https://wiki.theory.org/BitTorrentSpecification) data. 

### About
This project has been build for study purpose. I took help from [here](https://github.com/s3rvac/cpp-bencoding).

### Build Library from Source

```
cd into bencode directory
make
```

It will build library into`lib` directory.


### Documentation
Todo

### Example Usage
```
int main( )
{ 
   ifstream iFile;
   iFile.open("sample1.torrent", std::ifstream::in);
   nBencode::decode decoder;
   shared_ptr<nBencode::CItem> pItem = 
   decoder.decodeFile(iFile);
   
   //print bencode data in pretty format.
   shared_ptr<nBencode::CPrintPretty> print(
   new nBencode::CPrintPretty());
   print->Print(pItem);

   return 0; 
}

```