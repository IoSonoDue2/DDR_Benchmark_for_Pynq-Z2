La funzione prende in ingresso 2 array di int 512bit, uno di input ed uno di output, scrive in memoria l'array di input e lo rilegge per poterlo mandare in output.

la testbench manda un array randomico per l'input ed un array completamente inizializzato a zero per l'output, chiama la funzione benchmarkddr e verifica che l'array di output sia ora identico a quello di input.
