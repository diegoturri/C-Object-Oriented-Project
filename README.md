# C-Object-Oriented-Project
Project about keeping track of Personal Finance



Here is an example of how you can interact with the wallet if you want to try it:
  - Type +
  - insert the amount of the transaction (int)
  - insert the description of the transaction (string)
  - now the provisory balance is shown on the screen 
  - type 'save' in order to save the transactions inserted so far and be able to use them in the future
  - you can see the new transactions from the file 'cmake-build-debug/wallet.xml'
ONLY SAVED TRANSACTIONS WILL BE REPORTED BY THE 'report' COMMAND



Instead of giving a + command you can use other type of commands, here's the list:
  - + -> Add a sum

  - - -> Subtract a sum

  - save -> save the transactions

  - reset -> erase all the transactions

  - report -> Print a report (report--all, report--incomefirst and report--outcomefirst are the sorted versions)

  - stop -> Finish the execution of the program
