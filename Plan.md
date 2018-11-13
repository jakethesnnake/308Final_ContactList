# 308Final_ContactList
Authentication and Modification

Program that can add, remove, display or edit locally stored contacts, comparable to cell phone contacts.
Contact is struct with name/number/email/address etc.
Authentication
  Encrypted
    RSA
Store all usernames and passwords in login.txt
Store all contacts in (respective) user.txt file
Print to file (save or commit) - persistence

Data Structures
Dynamic Array[Contact] typedef
  -> phone#, email, name … -> next
Dynamic Array[Account] typedef
  Account.txt with [user1] – [password1] : has all accounts
  [user1].txt : has all contacts
  Filename is created and read based on username and is always retrievable
Account struct
Contact struct
“Search” (*through contact data*) Union
  user can enter char * for name
  user can enter long for phone number
Command Enum
  ADD / REMOVE / DISPLAY / SEARCH (Create VCard for account option)
Run-time state Enum
  Determines run time state
    Authentication state
    User’s contact state
Libraries
  Studio.h
  Studio.io
  String.h
  Strstr()
    can check if contact data is contained within search
 
Any changed data to user’s account OR user’s contacts will be written to the file after program terminates. Authentication file is opened in every session and an individual user file is selected, which is opened and closed exactly once.
 
The accounts.txt file determines the user’s contact file
The user’s contact file is written to and read from exactly once
VCARDS parsed in and out
