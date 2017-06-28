# Find-The-Way-And-Avoid-The-Boom

You’re required to build a game ‘Find-The-Way-And-Avoid-The-Boom’ in C program that fulfil
the below requirements/rules:
- The mission of the player that plays the game is to find the way through a masked
out map from entrance to exit without stepping on the boom.
- The game should have a 20 rows x 50 columns map, which you can masked the
area with asterisks (*) or any other symbol of your choice.
- The game should allow player to choose among 3 stages of difficulties. For example:
  - Beginner: 10 booms
  - Intermediate: 50 booms
  - Advance: 100 booms

   (Note: You may define your own number of booms which you think appropriate)

- Once the game started, all the booms will be scattered randomly in the map. The
booms should not be visible to the player.
- Your map should have an entrance and an exit. You can indicate it with a symbol of
your choice.
- The player is required to navigate their steps by inputting the option of directions (left,
right, top, and bottom) and number of steps they want to move. You’re required to
keep the move within the boundary of the map.
- Show the path that player navigate through by removing the mask in the map.
- Each player will have 3 lives, a live will be deducted when the player step on a boom.
Game will end when player has no remaining lives. The screen should display the
number of live of the player while the game progress.
- Or, game will end when player reach the exit without exhausted all their lives.
- Once game ended, the screen should display the total number of steps the player
has taken, and show the appropriate ending message, for example:
“You do not make it to the finish line”
“You make it! Brilliant!”
  - If total steps < 20: display “You need to try harder!”
  - If total steps between 20-50: “You need a better luck”
  - If total steps between 50-80: “Not too bad”
  - If total steps > 80: “You have the talent”


The solution should have input data validation, and design using proper logic and data
structure.

You need to use multi-subscripted array and you are required to improve your code structure
by using functions. You’re encouraged to add in any additional controls, validations or
messages which you think are appropriate.
