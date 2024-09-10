# RAID-Mapping
This program maps the location of sectors in a RAID device into the sectors of the hard disks that compose it.

Given a scenario composed of a RAID level T ("0", "1", "01", "10", "4", or "5"), the number of hard disks N, the size of the chunks C (in sectors), the number of sectors per disk S, Q queries will be asked for. Each query is a valid sector number in the RAID device, and this program specifies which hard disk and stripe contain the queried sector, and which other disk has a copy of (RAID levels 1, 01, and 10) or a parity for (RAID levels 4 and 5) this sector. 

# Restrictions
Hard disks are numbered from 0 to N-1. N is in the range [2,16].
  -N is always 2 for RAID level 1.
  -N is always an even number greater than 3 for RAID levels 01 and 10.
  -N is always greater than 2 for RAID levels 4 and 5.
  
Chunk size C is a number in the range [1,16] for RAID level 0.
  -C is always 1 for other RAID levels.
  
Stripes and disk sectors are numbered from 0 to S-1.
  -The number of sectors per disk S is greater than 1 and is always a multiple of C.
  -S is in the order of billions.
  
The number of queries Q is in the order of millions.

# Input Format
The first line of input has 5 items in this order: T, N, C, S, and Q. Follow Q lines, each with the queried sector number.

# Output Format
For each query, print one line in the output. Each line has two or three numbers. The first number is the hard disk number ([0,N-1]) that contains the queried sector. If more than one disk has a copy of the queried sector, print the one with the smaller number (for RAID levels 1, 01, and 10). The second number is the stripe ([0,S-1]) that contains the queried sector. The third number is the hard disk number ([0,N-1]) that contains the second copy of the queried sector for RAID levels 1, 01, and 10, or the hard disk number ([0,N-1]) that contains the parity affected by the queried sector for RAID levels 4 and 5.
