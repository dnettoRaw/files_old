#!/bin/sh
#dnetto LOLOLOL \o/

while [ 1 ] ; do 
	if [ -s $1 ] ; then echo " Usage:\n\tsh $0 [nombre de tretrimonos] [ dificulte: hard/easy ] \n\tdefaut en easy" && break ; fi
	u=$1
	while [ $u -ge 0 ] ; do u=`expr $u - 1` && r=$[ ($RANDOM % ($[ 19 - 1 ] + 1 )) + 1 ]
		case $r in 
			1)	echo "\n..#.\n..#.\n..##\n...."	>> map.fil;;
			2)	echo "\n..#.\n..#.\n.##.\n...." >> map.fil;;
			3)	echo "\n.##.\n.#..\n.#..\n...." >> map.fil;;
			4)	echo "\n.##.\n..#.\n..#.\n...." >> map.fil;;
			5)	echo "\n.#..\n.###\n....\n...." >> map.fil;;
			6)	echo "\n....\n...#\n.###\n...." >> map.fil;;
			7)	echo "\n....\n....\n.###\n.#.." >> map.fil;;
			8)	echo "\n....\n###.\n..#.\n...." >> map.fil;;
			9)	echo "\n.#..\n.##.\n.#..\n...." >> map.fil;;
			10)	echo "\n....\n..#.\n.##.\n..#." >> map.fil;;
			11)	echo "\n....\n....\n###.\n.#.." >> map.fil;;
			12)	echo "\n....\n....\n..#.\n.###" >> map.fil;;
			13)	echo "\n.#..\n.##.\n..#.\n...." >> map.fil;;
			14)	echo "\n....\n..#.\n.##.\n.#.." >> map.fil;;
			15)	echo "\n....\n##..\n.##.\n...." >> map.fil;;
			16)	echo "\n....\n....\n.##.\n##.." >> map.fil;;
			17)	echo "\n#...\n#...\n#...\n#..." >> map.fil;;
			18) 	echo "\n....\n####\n....\n...." >> map.fil;;
			19) 	echo "\n....\n.##.\n.##.\n...." >> map.fil;
		esac
	done
	cat map.fil | sed 1d > map.fillit
	 rm map.fil
break
done
