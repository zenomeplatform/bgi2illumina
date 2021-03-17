# bgi2illumina
Conversion of BGI-sequenced headers of FASTQ records to Illumina-compatible ones.

## Installation

Simply run make:
```bash
make          // this will build a binary
make install  // this will copy binary into /usr/local/bin
```
To delete existing "installation" run 
```bash
make uninstall
```

## Installation 

Compilation process is very simple and can be handled without `make`,
if you are more comfortable with it for some reasons.

Compile the source code with `gcc`:

```bash
gcc -o bgi2illumina bgi2illumina.c
```

or `clang`:
```bash
clang -o bgi2illumina bgi2illumina.c
```

## Usage

```bash
./bgi2illumina <instrument>:<run_number>:<flowcell_id> < input.fq > output.fq
```
The support for gz-compressed files is provided through piping through `bgzip -c` and `bgzip -cd` (or `gunzip -c`).

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
