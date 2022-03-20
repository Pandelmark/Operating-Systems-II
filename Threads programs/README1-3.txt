==Το ακόλουθο πρόγραμμα έχει υλοποιηθεί σε τερματικό linux και μεταγλωτιστεί με τον 'gcc' μεταγλωτιστή.==

To πρόγραμμα "threads1-3" σε C υπολογίζει «παράλληλα» το άθροισμα των τετραγώνων των στοιχείων
ενός διανύσματος Α (a1^2+a2^2+…+an^2) [με τη βοήθεια ‘p’ threads όπου το κάθε thread υπολογίζει το επιμέρους
άθροισμα ‘n/p’ όρων (τετραγώνων) του αθροίσματος – τα p, n, ai θα πρέπει να τα δίνει ο χρήστης
επίσης θεωρούμε ότι το ‘n’ είναι ακέραιο πολλαπλάσιο του ‘p’]. Πιο συγκεκριμένα, το κάθε thread
(α) να υπολογίζει τοπικά (σε μια τοπική μεταβλητή – π.χ. local_sum) τo επιμέρους άθροισμα που του
αναλογεί και (β) ενημερώνει στο τέλος με το τοπικό του άθροισμα μια κοινή μεταβλητή (π.χ. total_sum) η οποία
αντιπροσωπεύει το τελικό άθροισμα. Το τελικό αυτό άθροισμα πρέπει στο τέλος να τυπώνεται στην οθόνη.
Επίσης έχει εξασφαληθεί η προστασία του κρίσιμου σημείου του προγράμματος με τη χρήση mutex
ως μηχανισμός ‘κλειδώματος’ που παρέχεται από τα POSIX Threads.

Το αποτέλεσμα που εμφανίζει στην οθόνη το πρόγραμμα του αρχείου εικόνας "test result1-3" μπορεί να 
αναπαραχθεί με την τοποθέτηση των εξής τιμών:

- αριθμός όρων πίνακα: 8
- αριθμός νημάτων: 4
- μεταβλητή 1: 1
- μεταβλητή 2: 2
- μεταβλητή 3: 3
- μεταβλητή 4: 4
- μεταβλητή 5: 5
- μεταβλητή 6: 6
- μεταβλητή 7: 7
- μεταβλητή 8: 8

-- English version:

== The following program has been implemented on a linux terminal and has been compiled with the 'gcc' compiler. ==

The program "threads1-3" in C programming language calculates all at the same time the sum of the squares of the elements
of a vector A (a1 ^ 2 + a2 ^ 2 +… + an ^ 2) [with the help of ‘p’ threads where each thread calculates the individual
sum of ‘n / p’ terms (squares) of the sum - p, n, ai should be given by the user
we also consider that ‘n’ is an integer multiple of ‘p’]. More specifically, each thread
(a) calculate locally (in a local variable - eg local_sum) the subtotal
corresponds and (b) updates at the end with its local sum a common variable (eg total_sum) which
represents the final sum. This final sum must finally be printed on the screen.
The protection of the critical section of the program has also been ensured by the use of mutex
as a ‘lock’ mechanism provided by POSIX Threads.

The result displayed on the screen of the program image file "test result1-3" can be
reproduced by giving the following values:

number of table terms: 8
number of threads:
- variable 1: 1
- variable 2: 2
- variable 3: 3
- variable 4: 4
- variable 5: 5
- variable 6: 6
- variable 7: 7
- variable 8: 8