Χρησιμοποιόντας τις κατάλληλες εντολές "fork()" το πρόγραμμα "processes1-2" δημιουργεί συνολικά (μαζί με το κυρίως
πρόγραμμα) έξι διεργασίες, με την ακόλουθη δομή (δέντρο) συγγένειας:
	P0
	/ \
      P1   P2
          / | \
         P3 P4 P5
Το παρακάτω πρόγραμμα γλώσσας προγραμματισμού C ως κύριο μέρος της εργασίας της κάθε διεργασίας Pi τυπώνει ένα μήνυμα 
στην οθόνη που να δηλώνει το όνομά της (Pi), το PID της και το PPID της. Το πρόγραμμα συμπεριλαμβάνει επιπλέον
τις κατάλληλες εντολές αναμονής-επικοινωνίας ώστε να ικανοποιούνται οι ακόλουθοι περιορισμοί-απαιτήσεις: (α)
η διεργασία P0 πριν εκτελέσει το κύριο μέρος της εργασίας της περιμένει την ολοκλήρωση της διεργασίας P2,
και (β) η διεργασία P2 πριν εκτελέσει την κύρια εργασία της περιμένει την ολοκλήρωση όλων των παιδιών της.
Επίσης η διεργασία P0 πριν δημιουργήσει την P2 περιμένει να λάβει ένα μήνυμα 'hello from your first child' από
τη διεργασία P1 (και να το τυπώνει στην στην οθόνη). Τέλος, η διεργασία P0 με το πέρας της εκτέλεσής της
αντικαθίσταται από την εντολή ps.

-- English version:
Using the appropriate "fork ()" commands the "processes1-2" program creates a total (along with the main
program) six processes, with the following affinity structure (tree):
       P0
       / \
      P1 P2
	/ | \
       P3 P4 P5
The following programming language program C as the main part of the work of each Pi process prints a message
on the screen indicating its name (Pi), its PID and its PPID. The program also includes
the appropriate standby-communication orders to meet the following restrictions-requirements: (a)
process P0 waits for process P2 to complete before performing most of its work,
and (b) process P2 awaits the completion of all its children before completing its main task.
Also process P0 before creating P2 waits to receive the message 'hello from your first child' from
process P1 (and print it on the screen). Finally, process P0 at the end of its execution
is replaced by the ps command.