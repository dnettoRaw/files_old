# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    encript.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 21:41:40 by dnetto            #+#    #+#              #
#    Updated: 2017/04/20 10:49:49 by dnetto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
function echoc
{
	if [ $1 = r ] ; then echo "\033[31m$2\033[0m" ; 
	elif [ $1 = v ] ; then echo "\033[32m$2\033[0m" ; 
	elif [ $1 = j ] ; then echo "\033[33m$2\033[0m" ; 
	elif [ $1 = b ] ; then echo "\033[34m$2\033[0m" ; 
	elif [ $1 = R ] ; then echo "\033[35m$2\033[0m" ; 
	elif [ $1 = c ] ; then echo "\033[36m$2\033[0m" ; 
	elif [ $1 = s ] ; then echo "\033[37m$2\033[0m" ; fi
}
u1=$0
r="\033[31m"
v="\033[32m"
j="\033[33m"
b="\033[34m"
R="\033[35m"
c="\033[36m"
s="\033[37m"
e="\033[0m"
clear
echo "========================================================="
echo "======================= ${r}D${v}N${j}E${s}T${R}T${c}O$e =========================="
echo "========================================================="
echo "=\t1-chifrer\t\t\t\t\t="
echo "=\t2-dechifrer\t\t\t\t\t="
echo "=\t3-gerer key RSA\t\t\t\t\t="
echo "=\t4-gerer key Public\t\t\t\t="
echo "=\t5-je suis null, faire un vulgaire .tar\t\t="
echo "=\t6-bah il faut aussi decompresser\t\t="
echo "=\t7-Quitter\t\t\t\t\t="
echo "========================================================="
echo "========================================================="
echo "========================================================="
read m
if [ $m -eq 3 ] ; then 
	clear
	echo "========================================================="
	echo "=============== ${c}Creation de la key RSA$e =================="
	echo "=========================================================$v"
	sleep 01
	nr=00
	while [ -e mykey${nr}.pem ] ; do  nr=`expr $nr + 1`; done
	if [ $nr -lt 10 ] && [ $nr -gt 0 ]; then openssl genrsa -out mykey0${nr}.pem 2048 ;
	else  openssl genrsa -out mykey${nr}.pem 2048 ; fi
	echo "$e"
	sleep 0.5
elif [ $m -eq 4 ] ; then
	clear
	echo "========================================================="
	echo "============== ${c}Creation de la  key public$e ==============="
	echo "========================================================="
	echo "nom ou numero, exemple mykey${r}XX${e}.pem : \c" 
	read key
	nr=00
	while [ -e pub${nr}.key ] ; do  nr=`expr $nr + 1`; done
	if [ -e mykey${key}.pem ] ; then
		if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then openssl rsa -in mykey${key}.pem -pubout > pub0${nr}.key 
		else openssl rsa -in mykey${key}.pem -pubout > pub${nr}.key ; fi 
	elif [ -e ${key} ] ; then
		if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then openssl rsa -in ${key} -pubout > pub0${nr}.key 
		else openssl rsa -in ${key} -pubout > pub${nr}.key ; fi 
	else echoc r "[error 404 \"${key}\" not found]";fi
	sleep 0.5

elif [ $m -eq 1 ] ; then
	clear
	echo "========================================================="
	echo "======================== ${c}Crypt${e} =========================="
	echo "========================================================="
	echo "=\t1-standar aes-256-cbc \t\t\t\t="
	echo "=\t2-perso avec key ${c}[ex: pub${r}01${c}.key]${e}\t\t="
	#	echo "=\t(obs* pour une key perso entre le nom de la key)="
	echo "========================================================="
	echo "========================================================="
	echo "========================================================="
	read r
	if [ $r -eq 1 ] ; then 
		clear 
		echo "========================================================="
		echo "======================== ${c}Crypt${e} =========================="
		echo "========================================================="
		read -p "Nom du fichier source : " fichier
		nr=00
		while [ -e file${nr}.crypt ] ; do  nr=`expr $nr + 1`; done
		if [ -e ${fichier} ] ; then
			if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then cat ${fichier} | openssl enc -aes-256-cbc -e -out file0${nr}.crypt 
			else cat ${fichier} | openssl enc -aes-256-cbc -e -out file${nr}.crypt; fi	
		else echoc r "[ERROR 404 \"${fichier}\" not found]" && sleep 0.5; fi
		elif [ $r -eq 2 ] ; then 
			clear 
			echo "========================================================="
			echo "======================== ${c}Crypt${e} =========================="
			echo "========================================================="
			read -p "Nom du fichier source  : " fichier
			read -p "fichier avec la key.pub: " key
			nr=00
			while [ -e file${nr}.crypt ] ; do  nr=`expr $nr + 1`; done
			if [ -e ${fichier} ] ; then
				if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then cat ${fichier} | openssl rsautl -encrypt -pubin -inkey ${key} -out file0${nr}.crypt 
			else cat ${fichier} | openssl rsautl -encrypt -pubin -inkey ${key} -out file${nr}.crypt ; fi	
		else echoc r "[ERROR 404 \"${fichier}\" or \"${key}\" not found]" && sleep 1; fi	
	fi
	sleep 0.5
elif [ $m -eq 2 ] ; then
	clear
	echo "========================================================="
	echo "======================= ${c}decrypt${e} ========================="
	echo "========================================================="
	echo "=\t1-standar aes-256-cbc \t\t\t\t="
	echo "=\t2-perso avec key ${c}[ex: mykey${r}01${c}.pem]${e}\t\t="
	#	echo "=\t(obs* pour une key perso entre le nom de la key)="
	echo "========================================================="
	echo "========================================================="
	echo "========================================================="
	read r
	if [ $r -eq 1 ] ; then 
		clear 
		echo "========================================================="
		echo "======================= ${c}Decrypt${e} ========================="
		echo "========================================================="
		read -p "Nom du fichier source : " fichier
		nr=00
		while [ -e file${nr}.out ] ; do  nr=`expr $nr + 1`; done
		if [ -e ${fichier} ] ; then
			if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then openssl aes-256-cbc -d -in ${fichier} -out file0${nr}.out 
			else  openssl aes-256-cbc -d -in ${fichier} -out file${nr}.out; fi	
		else echoc r "[ERROR 404 \"${fichier}\" not found]" && sleep 0.5; fi
		elif [ $r -eq 2 ] ; then 
			clear 
			echo "========================================================="
			echo "======================= ${c}Decrypt${e} ========================="
			echo "========================================================="
			read -p "Nom du fichier source  : " fichier
			read -p "fichier avec la mykey.pem : " key
			nr=00
			while [ -e file${nr}.out ] ; do  nr=`expr $nr + 1`; done
			if [ -e ${fichier} ] ; then
				if [ $nr -lt 10 ] && [ $nr -gt 0 ] ; then cat ${fichier} | openssl rsautl -decrypt -inkey ${key} -out file0${nr}.out 
			else cat ${fichier} | openssl rsautl -decrypt -inkey ${key} -out file${nr}.out ; fi	
		else echoc r "[ERROR 404 \"${fichier}\" or \"${key}\" not found]" && sleep 1; fi	
	fi
	sleep 0.5

elif [ $m -eq 5 ] ; then
	clear
	echo "========================================================="
	echo "======================= DNETTO =========================="
	echo "========================================================="
	echo "=\t1-chifrer\t\t\t\t\t="
	echo "=\t2-dechifrer\t\t\t\t\t="
	echo "=\t3-gerer key RSA\t\t\t\t\t="
	echo "=\t4-gerer key Public\t\t\t\t="
	echo "=\t5-je suis null, faire un vulgaire .tar\t\t="
	echo "=\t6-bah il faut aussi decompresser\t\t="
	echo "=\t7-Quitter\t\t\t\t\t="
	echo "========================================================="
	echo "========================================================="
	echo "========================================================="
	read m
	echo 5
elif [ $m -eq 6 ] ; then
	clear
	echo "========================================================="
	echo "======================= DNETTO =========================="
	echo "========================================================="
	echo "=\t1-chifrer\t\t\t\t\t="
	echo "=\t2-dechifrer\t\t\t\t\t="
	echo "=\t3-gerer key RSA\t\t\t\t\t="
	echo "=\t4-gerer key Public\t\t\t\t="
	echo "=\t5-je suis null, faire un vulgaire .tar\t\t="
	echo "=\t6-bah il faut aussi decompresser\t\t="
	echo "=\t7-Quitter\t\t\t\t\t="
	echo "========================================================="
	echo "========================================================="
	echo "========================================================="
	read m
	echo 6
elif [ $m -eq 7 ] ; then
	clear
	echo "========================================================="
	echo "======================= \c"
	echoc r "bye, bye!\c"
	echo " $e======================="
	echo "========================================================="
	sleep 01
	clear
	exit
else
	clear	
	echo "$r[Error]$e\n$m est un Numero nom valide"
	sleep 1
fi 
sh $u1
