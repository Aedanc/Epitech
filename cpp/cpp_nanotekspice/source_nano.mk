##
## source_nano.mk for nanotekspice in /home/quersi_l/rendu/cpp_nanotekspice
## 
## Made by Laurent QUERSIN
## Login   <quersi_l@epitech.net>
## 
## Started on  Wed Feb 15 12:15:25 2017 Laurent QUERSIN
## Last update Sat Mar  4 00:03:57 2017 Laurent QUERSIN
##

PATH_SRC_NANO	=	sources/
PATH_SRC_CHIPSET=	sources/chipsets/

SRC_NANO	+=	$(PATH_SRC_NANO)Error.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)ParserLexer.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)CommandParser.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)NanoTek.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)AComponent.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)Circuit.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)Link.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)Input.cpp
SRC_NANO	+=	$(PATH_SRC_NANO)Output.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4001.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4008.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4011.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4030.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4040.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4069.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4071.cpp
SRC_NANO	+=	$(PATH_SRC_CHIPSET)Chipset4081.cpp


SRC_NANO	+=	$(PATH_SRC_NANO)main.cpp
