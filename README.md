# The SimulBank Project

A year 1 group project with the goal was to create a mock ATM. This included reading data from a serial port connected to a card reader, creating the bankomat program, connecting the bankomat to a backend server and connecting that server to a database with user information.

## Participants and credits
Everyone was involved in all sections and/or tools of the specified product, but specializations and extras include:

Me: Backend servers, display of user data, general digestion of what is supposed to be done, netbank (with user and card creation options).

[@KarolusPaulus](https://github.com/KarolusPaulus): PIN code module and its conversion into a separate library, visuals.

[@nidacnr](https://github.com/nidacnr): Transaction history window and functions.

[@Tappivanukas2](https://github.com/Tappivanukas2): Transaction window and functions.

[@zopuli](https://github.com/zopuli): Reading data from the serial port, UI.

## Tools, languages etc. involved
The frontend was written in C++ and used Qt Creator's UI tools. The backend was Node.js-enabled JavaScript and hosted on Render for 24/7 access. The database utilised MySQL and was put into the cloud service provider Aiven for the final product and ease of access.

## Samples
#### Starting window with PIN entry
![PIN request](readme_images/bankomat_pin.png?raw=true "PIN request")

#### Main menu
![Bankomat main page](readme_images/bankomat_menu.png?raw=true "Bankomat main page")

#### User profile window
![Bankomat user details](readme_images/bankomat_user.png?raw=true "Bankomat user details")

#### The structure of the system
![General structure](readme_images/structure.png?raw=true "General structure")

#### The structure of the database
![Database structure](readme_images/database.png?raw=true "Database structure")

#### The logic behind the Bankomat
![Bankomat logic graph](readme_images/bankomat_logic.png?raw=true "Bankomat logic graph")

#### Netbank's user profile page
![Netbank user details](readme_images/netbank_profile.png?raw=true "Netbank user details")

#### Youtube demo (in Finnish)
[![Demo](https://img.youtube.com/vi/evrqCWDBZTA/0.jpg)](https://www.youtube.com/watch?v=evrqCWDBZTA)
