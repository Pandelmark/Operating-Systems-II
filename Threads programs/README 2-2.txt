==Το ακόλουθο πρόγραμμα έχει υλοποιηθεί σε τερματικό linux ubuntu και μεταγλωτιστεί με τον 'gcc' μεταγλωτιστή.==

Έστω ένας δυσδιάστατος πίνακας ακεραίων Α (ΝxN). Το παρακάτω πρόγραμμα βρίσκει το 'μέγιστο' 
στοιχείο (m) του πίνακα Α [με τη βοήθεια ‘p’ threads όπου το κάθε
thread υπολογίζει το επιμέρους μέγιστο Ν/p γραμμών του πίνακα – τα 'p', 'Ν', 'Α' τα οποία
να δίνει ο χρήστης. Θεωρούμε ότι το 'Ν' είναι ακέραιο πολλαπλάσιο του 'p']. Στη συνέχεια το
πρόγραμμα φτιάχνει επίσης παράλληλα (με τη βοήθεια των ‘p’ threads που έχουν
εξαρχής δημιουργηθεί) ένα νέο πίνακα D (ΝxN) (τον οποίον τυπώνει στο τέλος στην οθόνη), 
στον οποίον αποτυπώνεται η 'απόσταση' του κάθε στοιχείου (Aij) του πίνακα Α από το m :

				Dij = m – Aij


-- English Translation:
== The following program has been implemented on linux ubuntu terminal and has been compiled with the 'gcc' compiler. ==

Suppose a two-dimensional array of integers A (NxN). The following program finds the 'maximum'
element (m) of table A [using ‘p’ threads where each
thread calculates the individual maximum N / p lines of the table - the 'p', 'N', 'A' which
are been given by the user. We consider that 'N' is an integer multiple of 'p']. Next, the program builds at the same time
(with the help of the ‘p’ threads they have a new D (NxN) table is created from the beginning (which will be printed at the end on the screen),
showing the 'distance' of each element (Aij) of table A from m:

				Dij = m - Aij