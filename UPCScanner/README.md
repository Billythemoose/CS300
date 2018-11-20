# Barcode Scanner 

This program compares search times between a Binary Search Tree and a Sorted Array.
It loads a CSV containing a UPCs with corresponding descriptions into both data structures then searches the two stuctures for a user provided UPC.
It will output the UPC and description if found and the time in seconds it took to search each data structure. 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. This is not intended for use in production. 

### Prerequisites

CSV with UPC and descriptions. CSV must be delimited with a comma (','). The program expects the first row of the CSV to contain column header information and will ignore the first line. 
Example CSV
```
column_one,column_two
12345678,"Basic UPC with descriptive description"
98765432,"UPC does not have to be accurate, any int64_t is accepted"
```

### Installation and Running

Clone the current repo locally
In a CMD or PowerShell window, navigate to the folder containing the "UPCScanner.exe" file
Run "UPCScanner.exe"
The program will begin with "File Path" 
Enter the full file path for the CSV to be loaded
Example:
```
Clone to C:\Testing
Open CMD window
cd C:\Testing\UPCScanner\Debug
UPCScanner.exe
File Path: C:\Testing\upc_corpus.txt
Loading. This will take some time
```

The program will load the information from the provided file path
When prompted, enter a UPC to search for. 


## Built With

* [Visual C++](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads) - Development Language
* [VisualStudio](https://visualstudio.microsoft.com/) - IDE

## Authors

* **Michael Thomas** - *Initial work* - [billythemoose](https://github.com/billythemoose)
