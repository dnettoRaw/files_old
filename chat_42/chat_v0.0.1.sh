#!/bin/sh

## ce project est juste pour s'amuser, j'en suis pas au top en script
## et oui je fait des erreurs, donc si tu trouve des bugs ou des amelorations
## envoi moi un mail ou un signe de fume(essai par mail quand meme) 
## mail :	dnetto@student.42.fr  

#################################################
#	ici le chemain du fichier pour l'echange	#
#	si tu sais pas qu'est  que ça veut dire		#
#	laisse le chemain par defaut, attention		#
#	de mettre le meme chemain sur les .sh		#
#################################################

way="/sgoinfre/goinfre/Perso/dnetto/.chat"

#################################################




function porcents
{
	t=0
	while [[ $t -lt $1 ]] ; do t=`expr $t + 1` && echo "=\c" && sleep 0.5 ; done
}
function attendre
{
	nb=0
	echo "${w}\tOn attend\n[${g}\c"
	while [ $nb -lt $1 ] ; do 
		#je essai de lire
		nb=`expr $nb + 1` && sleep 0.1 && porcents 1

	done
	echo "${w}]"
}
stty erase ^?
TRUE_FALSE=0
time=`date '+%d-%m-%HH'`
w="\033[0m"
r="\033[31m"
g="\033[32m"
y="\033[33m"
b="\033[34m"
v="\033[35m"
c="\033[36m"
s="\033[37m"
ex="trololo"
clear
echo "${r}===${w}===${b}===${s} Chat ${c}42 ${g}==${y}==${b}=${y}==${g}==${w}"
while [ ! -z $ex ] ; do
	echo "salut!!\n${g}1${w}-pour lancer un chat\n${g}2${w}-Pour attendre un call"
	echo "${r}===${w}===${b}===${s} ======= ${g}==${y}==${b}=${y}==${g}==${w}"
	read res
	if [ $res -eq 1 ] ; then
		clear
		echo "${r}===${w}===${b}===${s} Chat ${c}42 ${g}==${y}==${b}=${y}==${g}==${w}"
		read -p "coucou $USER,
tu veux parler avec qui? " nick
		echo "je vais m'en occuper, attend que ${y}$nick${w} repond"
		ldapsearch -QLLL uid=$USER | grep uid: | cut -d ' ' -f2- > me
		ldapsearch -QLLL uid=$nick | grep uid: | cut -d ' ' -f2- > pt
		echo "\t\tconection\t\t|"
		while [ ! -z "$ex" ] ; do
			echo "[${g}===\c"
			if [ ! -s me ] ; then echo "\n${r}je te trouve pas dans la base de donne T.T${w}" && break ; else porcents 3 ; fi
			sleep 0.5
			if [ ! -s pt ] ; then echo "\n${r}je trouve pas le ${c}${nick}${r} dans la base de donne T.T${w}" && break ;else porcents 3 "===\c"; fi
			sleep 0.5
			me=`cat me` && pt=`cat pt` &&  rm me pt
			echo $me > $way/$pt.$me.startcall
			echo "==============================${w}]\nPour nous c'est fait, on lui attend maintent :D\n"
			break
		done
		while [ ! -e $way/${pt}-${me}_${time} ] ; do 
			attendre 25
			 if [ -e $way/${pt}-${me}_${time} ] ; then break ;fi
			echo "${y}il n'as pas repondu l'invitation tu veux recommencer ? y/n : ${w}\c" 
			read dfr && if [ ! $dfr = y ] ; then break ; fi
		done
		if [ -e $way/${pt}-${me}_${time} ] ;then TRUE_FALSE=1 && way=`expr $way/${pt}-${me}_${time}` && userand="$pt and $me";fi
	elif [ $res -eq 2 ] ; then
		clear
		nb=0
		while [ ! -e $way/$USER.*.startcall ] ; do 
			#je essai de lire
			clear
			attendre 25
			echo "${y}il n'as pas envoyer l'invitation tu veux recommencer ? y/n${w}" 
			read dfr && if [ $dfr = y ] ; then clear ; else break ; fi
		done
		while [ -e $way/$USER.*.startcall ] ; do
			pt=`cat $way/$USER.*.startcall` && rm $way/$USER.$pt.startcall 
			if [ -e "$way/${USER}-${pt}_${time}" ] ; then rm -rf  "$way/${USER}-${pt}_${time}" && mkdir "$way/${USER}-${pt}_${time}" ; else mkdir "$way/${USER}-${pt}_${time}"; fi
			break
		done
		if [ -e ${way}/${USER}-${pt}_$time ] ; then TRUE_FALSE=1 && way=`expr $way/${USER}-${pt}_$time` && userand="${USER} and $pt"; fi
	fi
	break
done
#############################################################
while [ $TRUE_FALSE -eq 1 ] ; do
	mkdir ~/Documents/.chattmp
	cd ~/Documents/.chattmp
	openssl req -x509 -nodes -days 100000 -newkey rsa:2048  -keyout priv.${USER}.pem  -out pub.${pt}.pem  -subj '/'
	mv pub.${pt}.pem $way
	clear	
	echo "${r}===${w}===${b}===${s}   Chat ${c}42   ${g}==${y}==${b}=${y}==${g}==${w}   $userand  \c" > chat.txt 
	echo "${r}===${w}===${b}===${s}   welcomme  ${g}==${y}==${b}=${y}==${g}==${w}" >> chat.txt
	echo "${y}\t\t\t      { pour les options: %h } ${w}" >> chat.txt
	cat chat.txt
	i=2
		echo "$USER [${c}`date '+%Hh%M'`${w}]->\c"
	while [ -e chat.txt ] ; do 
		#while [[ $k = "" ]] ; do
		read k #& if [ -e $way/sd.cryp ] || [ ! -z $k ] ; then break ; fi
		#done
		########
		if [ -e $way/sd.cryp ] ; then
		openssl  smime -decrypt  -in  $way/sd.cryp  -binary -inform DEM -inkey priv.$USER.pem  -out  cat.tmp
		diff chat.txt chat.tmp | sed 1,1d | cut -d ' ' -f2- >> chat.txt  && rm chat.tmp
		fi
		########
		if [[ ${k:0:1} = \% ]] ; then
			case ${k:1:2} in
				h)
					echo "\n\tHelp-me!!!\n\n\t\t%${r}h${w} - afficher help-me\n\t\t%${r}c${w} - Clear la conversation\n\t\t%${r}q${w} - Quit la conversation\n";;
				c) 	echo "${r}===${w}===${b}===${s}   Chat ${c}42   ${g}==${y}==${b}=${y}==${g}==${w}   $userand  ${r}===${w}===${b}===${s}   welcomme  ${g}==${y}==${b}=${y}==${g}==${w}${y}\n\t\t\t       { pour les options: %h } ${w}" > chat.txt && clear && cat chat.txt ;;
				q)  break;;
				*) echo "${r}comande non valide sorry ${c}T${w}.${c}T${w}"
			esac
		cat chat.txt | sed 1,${i}d
		else echo "$USER [${c}`date '+%Hh%M'`${w}]: $k" >> chat.txt && clear && cat chat.txt; fi 
		i=`expr $i + 1`
		#######
		openssl  smime  -encrypt -aes256  -in chat.txt  -binary  -outform DEM  -out $way/$USER.cryp $way/pub.${pt}.pem 
		#######
		echo "$USER [${c}`date '+%Hh%M'`${w}]->\c"
		unset k
	done
	rm -rf ~/Documents/.chattmp
	break
done
#############################################################
echo "========== ${r}bye${w} bye${b} bye${w} ==========="
sleep 1.5
clear
if [ -e "$way/${USER}-${pt}_${time}" ] ; then rm -rf "$way/${USER}-${pt}_${time}" ; fi
