//
// Pour read cmd shell comme fichier/direct en c
// voir bookmark google Run system command
// FILE* fd;
//
// fd = popen("find .", "r");
// char buff[101];
// while (fgets(buff, 100, fd))
// 	printf("%s", buff);
// return (0);

// Opti Fabien, avoir global const plutot que macro
// //h
// extern const double	my_pi;
//
// //c
// const double	my_pi = 3.14159265;


Avec Seb, mardi 16 juillet, 2:01
Comportement etrange, fonction big int round, enleve un parametre dans la fonction mais dans le main on laisse le param et le prototype tel quel et pas de crash a la compil ni pdt le fonctionnement, mais il ne fonctionne pas, il est corrompu.
D'apres seb, on peut faire du polymorphisme comme ca avec des param variable mais il peut y avoir des pb de stack, on va pas chercher le bon param en memoire c'est pour ca que ca marche pas.