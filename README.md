# Kallisto
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: Kallisto 0.48.0


PluMA plugin to run Kallisto (Bray et al, 2016) aligner

The plugin accepts as input a TXT file.  The first line contains the index.
All lines after contain the names of the FASTQ files to align to the index.

Kallisto will output a TSV file of index identifiers and counts,
and additionally a BAM file mapping aligned sequences to these identifiers,
in the user-specified output directory.
