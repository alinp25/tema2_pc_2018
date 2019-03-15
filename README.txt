--------------------------------------------------------------------------------
Tema 2 - Seria CC - Trivia Game
Nume: Pisica Alin-Georgian
Grupa: 314CC
--------------------------------------------------------------------------------
Timpul petrecut pe tema: ~ 6 ore
--------------------------------------------------------------------------------
Descrierea proiectului

> Tema proiectului este reprezentata de realizarea jocului de Trivia, folosind
biblioteca grafica "ncurses". 
> Jocul este structurat sub forma unui joc single-player, in care utilizatorului
ii revine rolul de a raspunde la diferite intrebari de cultura generala. 
> Pentru fiecare intrebare la care jucatorul raspunde corect, scorul sau creste 
cu 10, iar in caz contrar scade cu 5. 
> In urma fiecarui meci, scorul maxim all-time este actualizat. 
> Exista si 2 intrebari ajutatoare ce vin in ajutorul jucatorului (50/50, Skip 
the question).
--------------------------------------------------------------------------------
Citirea intrebarilor

> Se face din fisierele transmise ca parametru la rularea programului
> Intrebarile existente in momentul de fata:
    - 2 fisiere:
        # Questions.txt    (19 intrebari)
        # Questions2.txt   (23 intrebari)
    - Numarul total de intrebari: 33
    - Capacitatea totala initiala alocata pentru intrebari: 32
        => este necesara realocarea memoriei prin dublarea capacitatii (bifat)
--------------------------------------------------------------------------------
Structura proiectului

* Makefile
> Include 3 reguli:
    - build ->  compileaza programul
    - run   ->  ruleaza programul folosind ca date de intrare pentru intrebari 
                fisierul "Questions.txt"
    - clean ->  sterge fisierele "*.o" obtinute in timpul compilarii, cat si 
                executabilul

* main.c
> Fisierul "main.c" reprezinta punctul de start al aplicatiei
> Intrebarile sunt stocate intr-un array de structuri alocat dinamic ce isi 
dubleaza capacitatea cand maximul este atins
> Este apelata functia "readFiles" ce efectueaza citirea intrebarilor din 
fisierele transmise ca parametru (vezi "Utils.c & Utils.h")
> Este apelata functia "playGame" ce incepe jocul (vezi "Game.c & Game.h")

* Utils.c & Utils.h
> intrebarile sunt pastrate in structuri ce contin:
    - intrebarea (string de maxim 200 de caractere)
    - cele 4 raspunsuri (string-uri de maxim 200 de caractere)
    - raspunsul corect (int), de la 0 la 3, corespondent literelor de la A la D
> intrarile din Hall of Fame sunt pastrate in structuri (UserEntry) ce contin:
    - nume
    - scor
> "copyquestion(...)" copiaza datele dintr-o structura a unei intrebari in alta
> "readfiles(...)" citeste intrebarile din fisierele transmise ca parametru

* Game.c & Game.h
> "rebuildQuestions(...)" readuce intrebarile la cele originale 
> "playGame(...)" incepe jocul 
    - jocul ruleaza intr-un loop pana la selectia optiunii "Quit Game" in meniu
    - odata ce jocul incepe (este selectata optiunea "New Game") sunt parcurse
        intrebarile si afisate progresiv (vezi "Question.c & Question.h")
    - in functie de valoarea returnata in urma intrebarii, fie se trece la
        intrebarea urmatoare, fie este afisat meniul
    - in finalul loop-ului, variabilele sunt resetate la valoarea initiala, in 
        vederea inceperii unui nou joc, iar scorul final este afisat, eventual
        insotit de actualizarea scorului maxim

* Menu.c & Menu.h
> "printMiddleMenu(...)" afiseaza meniul in centrul ecranului (facand jocul
    responsive)
> "displayMenu(...)" afiseaza meniul intr-un loop pana la apasarea tastei ETNER,
    fiind astfel facut accesul catre una din cele 3 optiuni("New Game", 
    "Resume", "Quit Game")

* Question.c & Question.h
> "displayQuestion(...)" afiseaza intrebarea transmisa ca parametru si 
    returneaza:
    - 0 daca raspunsul e gresit
    - 1 daca raspunsul e corect
    - 2 daca se doreste revenirea la meniu
    - 3 daca se foloseste optiunea ajutatoare 50/50
    - 4 daca se foloseste optiunea ajutatoare "Skip the question"
> Data si ora sunt actualizate la apasarea fiecarei taste, obtinute prin cadrul
    functiei "getCurrentTime()" (vezi "TimeManipulator.c & TimeManipulator.h")

* ScorePrinter.c & ScorePrinter.h
> "displayScoreAndNumberOfQuestions(...)" afiseaza scorul obtinut, numarul de 
    intrebari gresite si corecte; afiseaza scorul maxim si anunta utilizatorul
    in cazul in care intra in Hall of Fame
> daca utilizatorul intra in Hall of Fame, este adaugat in fisierul 
    HighScore.txt (vezi "HighScoreForm.c & HighScoreForm.h" si 
    "HighScoreChecker.c & HighScoreChecker.h")

* RNG.c & RNG.h
> Folosite pentru generarea variantelor ce vor fi eliminate la varianta 
    ajutatoare 50/50
> "getRandomNumber(int n)" returneaza un numar intreg pozitiv mai mic decat n
> "randomOutOfOne(int a, int x)", returneaza un numar mai mic decat x, diferit
    de a
> "randomOutOfTwo(int a, int b, int x)", returneaza un numar mai mic decat x, 
    diferit de a si b

* TimeManipulator.c & TimeManipulator.h
> "getCurrentTime()" returneaza data si ora curenta

* HighScoreForm.c & HighSCoreForm.h
> Construit sub forma unui formular
> Anunta utilizatorul ca urmeaza sa fie adaugat in Hall Of Fame
> Solicita un input utilizatorului, fiind reprezentat de numele acestuia

* HighScoreChecker.c & HighScoreChecker.h
> "readEntries()" citeste cele 10 intrari din fisierul "HighScore.txt", sub
    forma unui array de structuri de tip UserEntry transmis ca parametru
    - Intrarile sunt de forma (scor, nume)
> "shouldAllToAllTimeHighScores(...)" verifica daca scorul utilizatorului, 
    transmis ca parametru, este mai mare decat orice alt scor din fisierul 
    "HighScore.txt". In caz afirmativ, returneaza 1, caz in care user-ul va
    fi adaugat in Hall of Fame
> "addToAllTimeHighScores(...)" gaseste pozitia pe care utilizatorul va fi 
    adaugat si modifica ordinea tuturor jucatorilor, urmand ca aceasta sa fie
    re-printata in fisierul "HighScore.txt"

* HallOfFamePrinter.c & HallOfFamePrinter.h
> "printHallOfFame()" afiseaza, la finalul jocului, primii 10 utilizatori 
    all-time, ordonati in functie de scor

--------------------------------------------------------------------------------
Bonusuri adaugate:
- Culori
- Aplicatia e responsive 
- Hall of Fame:
    - pastreaza primii 10 jucatori
    - capabilitatea de introducere a username-ului la finalul jocului, in cazul
        in care utilizatorul este demn de Hall Of Fame
    - username-ul persoanelor intrat in Hall of Fame este structurat sub forma
        unui sir de caractere ce poate contine litere (mari si mici) ale 
        alfabetului englez; tasta backspace sterge ultima litera scrisa la
        introducerea numelui
