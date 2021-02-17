# Hanging Pointers of Babylon
 
Authors: [Raymond Yuan](https://github.com/raymondlyy), [Shawn-Michael Kern](https://github.com/PurebreadDragon), [Jane Ran](https://github.com/jran26), [Zinal Patel](https://github.com/midgetdemon)  
Team Name: Lembirdox

## Project Description
We are making a text-based dungeon crawling RPG. The player will experience a simple storyline and various randomly-determined events and encounters. Every in-game quest will be individually themed and populated, allowing for each one to be unique. In each random occurrence, the player will be presented with different options relating to the content of the current scenario while progressing towards the end of their journey. 
* Why is it important or interesting to you?  
We are all epic gamers who appreciate gaming--and as epic gamers, we must make an epic game for this project while enjoying the experience of making it. This project proposal gives us the most creative freedom in story and design and allows us to both utilize and expand on our understanding of C++. 
* What languages/tools/technologies do you plan to use? (This list may change over the course of the project)  
C++ is the only confirmed tool we will be using. We have discussed utilizing graphic design tools at a future point of the project, but we are keeping that ace tucked into our sleeves for now.  
* What will be the input/output of your project?  
The player will interact with the game through console/text inputs and the game will output a text description of the result of the player's actions along with their options for what to do next. If time permits, we may upgrade it to display images or simple animations.  
* What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:  

We will be using Composite and Decorator. For the composite pattern:  
   * Why you picked this pattern and what feature you will implement with it  
   We selected Composite for easier implementation of similar objects (making enemy types that derive from a generic Enemy class, for example, and having all things in the game be Entity class objects).  
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want to have a large variety of entity class derived-types but still allow the player to interact with each of them in unique yet consistent ways. 
   * Why the chosen design pattern will lead to a good solution to that problem  
   Using a composite structure of subclasses derived from one master "entity" class saves time from having to rewrite the same methods each time for every new enemy type. On top of that, this keeps the expected results of common actions consistent with other entities. This design pattern can be extended to the "room" object as well, where one master room object contains some basic functionality such as "observe" or "search" and subclasses such as battle rooms, trapped rooms or loot rooms derive from said master room object.
   
For the decorator pattern: 
   * Why you picked this pattern and what feature you will implement with it  
   We selected Decorator for more efficient addition of unique attributes to special types of the same class (making enemy variants from the same type of enemy, for example).
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want to have special variants of rooms and enemies. We also want to give additional attributes and features to the main character as he/she progresses through the game.  
   * Why the chosen design pattern will lead to a good solution to that problem  
   We can "decorate" enemies and rooms of the same type with additional features while keeping others the same. We can "decorate" the main character with extra features from the items or upgrades he or she gains as the game progresses.

## Design Documents

Class diagram: [[link]](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Final%20Project%20OMT%20Diagram#R7V3ZcuK6Fv0aqs55SMqzyWPI1Dk3Uye5PTwKLMA3xuIYEUJ%2F%2FZU8gC3J2AYbHKKqVArLs9dee9KW1NEvJh83AZiO75EDvY6mOB8d%2FbKjadaZQf7ThmXU0FXtqGEUuE7UpK4bXtw%2FMG5U4ta568BZ5kCMkIfdabZxgHwfDnCmDQQBWmQPGyIve9cpGEGu4WUAPL71p%2BvgcfwWmr1u%2Fwbd0Ti5s2qdRXsmIDk4fpPZGDhokWrSrzr6RYAQjn5NPi6gR79d8l1%2B3i5%2Fendv1s0%2F32f%2Fgv%2F2%2FvP68OMkuth1lVNWrxBAH2996T9vw%2BtvP4z%2F%2FZo%2BXX9fKDfn%2FX9O4lOUd%2BDN4%2B915WMXL%2BM3xsvkM84W7sQDPtnqDZGPX%2BI95CP0gOeOfPJ7QJ4OBqThHQbYJQicxzswmpLWwdj1nDuwRHP6DjMMBm%2FJVm%2BMAvcPuSzwyC6VNJDdAY6FSbMyR7zQM0mzQloDOCPHPCUfRl013YEZjo8ZIM8D05nbDx%2BYHjIBwcj1ewhjNEkuhOa%2BA514a4V0uIED9LaSHXp%2BSThi2OjXgB8pYYzhuYFoAnFAPrUS79WVGI6YamYieYu14KpW3DZOCS1pjQkTk2W0uvbqds%2BEXMAfkY%2Bwuh%2B5YeZ%2BqlH2fsztgEeA9wGGPfoZZ2kxJD9Sr7puCoWzgqCqnKA%2BgAnkxJR8aZwSSQ8Oca5AzqZg4Pqju%2FCYS2Pd8hy%2FKW1C5NyhFwrD2HUc6IfCggEGkTxRCZki18fhpzB75I98sAvl1OyY5IEuyLa63iZ%2F9PAAXyCfyBVwQwGCRFgXkAqsQLQ20rZYtJZZxKoimxakDKQb8PMvZg%2BLjzus%2Fnobeu%2FXY%2F1fgAWK5hzjwO3PMZwdHYobtMkYT7z4Zw6GZeHPxdrU9oe18PE0Dutb%2F528EQp4u%2FKVoK6f1nb3wFDrPK37rudi94uzun6oVcU4sApXebAv4WwQuFPsIv%2Fo4G5KPav6ll5WbUBqBs%2FaAcXwR9gggSwJpLlHp0r4fDyOHHieG8ZssYJShfFMAbITghG9XALlK0X68kTl4NZ5uHUBtB7oQ%2B8JzdxQbeiXQXQsA%2FmhPGW1W9J96jbETpMn53BIgrdvkIRZ47%2F%2Blvwsy8%2BzPSpa4fNZPJQOdYTnAQw4GHMyLIrMsNSXYVmJRJLMTEStSERUfQPd8zMsKpNh0bvtzbDYnLBeeGB2fG58Sd1ilZattqRY%2BBTZHXynyfyjBHAbe2FtBPDgeZMz6c7VzsqyGZIavDlx3jqHlfPp0Xpy9YPYPbhq1XluRiHz7GhhrF%2FBquqhNWzyAJtULPSdc9rvTLb6HqKOcI80xZ6yqkSb166XJPwKXNms3wudEUw8e%2Bj10eJq3dALG8iORFIqO8IzNA8GsJh5xPUfwRJRM33ajfwUARlAD2D3Pdv9vsFtfqKCu3aZtW7WZbYUPXuJ6CXjs9byUP1C0VfgLlRbjyWfLr3y4aR017oM%2FGoM%2FAxl68DvrFCCBYGfbpQI%2FOx2BH4qn0Z8hgsQOFe%2Fno7UthUashV5P0%2F4x6ubCMV75MPj63fd3keJoG1FFCjEkc%2FDhGbjdTmVXTOlUdxnx7gQxS6HIgXwHjnu0BUkfz87kEPiD18gDwXh65BHuFKvzSYB3mt3uPgB%2BY4aDtavnq6pbkZL9443lrDhO204WI85REwga3WMyHTj2PaWMaLOXMiymWdpOkbkjf0zIpFTyRBRVl%2FXGCJaJlMNrZbURFv2DZrs%2Fdpcfc27M8df%2BlVs3ezSMnaAIFFcmsvXYT8QsIRK57OjWGu9ZnWsDx9I8hmBn9F9vzLSW8Ui9kakD16FrfFIcxh%2F%2BVCkMoFLh5iNVQLysL67AZ6D8Ezq7oEBzu9%2FjPBNonIfRe5jKlCPmz4t7Rsj9F47KsUdzrzDdQN9ArhouFSK0yx4%2FdjN7qVCVjQNgXHAbBzqTDUTvnbp1oeLf8V40d%2B%2F6e9TM966%2FEjtulwmGz557%2FCkU9tMtn%2Bnd67PC7eSEzuiMHK7gFacF48%2FZWFAm5dx2jFYNZVuxs%2FXdDt7iW2DVS0JIAqCVYI7WKYOixmY%2F8Ba9j66ZjLyHF1x2whDPCZB4wT%2BhGxGRc8dzfIo4fsB%2BTWiv%2Bi%2Bp%2FFydo7DeDR3%2FyUcQn8GxQfcg9Gm88nujae%2FTCHhDxeqj8EUhsoVU%2BW6GLsYvhBVSdsWAZhmbXCf3H0Uui%2BPcxyZ6LDdAcHbI1WwOKTJqUIpNYsTTF1eaZdShfk0yg2KGZEzRTGqIVCMZ4xo1jd2pYSrk9J1sYnL6LrU56ftTwDT%2BDls0RSdc4y0jHLLaLZTs0C3JYpUPVUUu4oyJRtPMHDJN6M5nb3oyeRDpvVk%2FlDejXk%2BUyARZk2pP0Y5dVVG0kqXh9hMDtEqp03rUng6r%2FA2CfLh88wrp2Alu7%2FTolvkFGR8AvXAPoFhlvUJchzFBpLaXYsx711rO8nuKmbmQqs6k31Jdolhae2S7C2ldBtGNO7t2u2TbEupSbJt1jPt7lmyS3T5SsneTrLbJLC2XpfAMn08htVYDepGbZAe1IUmfSBO%2BG8oRN2t%2B1CQdKrYoxg13YOPzIFV%2Bxk7DUVJpmGK5SUtm0m9SCZz2FgxIJ8%2FolVkG6blkNnCAhZV6tQTgd1YstCQA8cagFXUfyfkcEOoJqYjharM%2BTcHtyXIbO2XxfxIwUfHcfFS2uo6bbVla6dts9YGnwuKoJc0r0xzo3oFzl5pbsqy4QZgPbix5quGpbFuDu7DG2uexVeTqbTV9drqbl7isAj3RB3Uz3M%2Bty15vgvPzXZba4vn%2Bfc5femSHE9b6jZV6Leb9wYzetoWqHthJb5lNCUHvH0vUQAviV9ArFYUyoufj8%2BpvcMBJqjFtUCRpY%2BqgTq0WGgqpaBuKTh8CT2fk%2Bmh%2FDnxJNLbIn3w8do2n4KJpk%2BQWNeN9eFnMrf4blEO5jgHwydeqmN8bLmYInz3OIRb%2FHz5xfMySGsC74Mrb76rjIO5sUESameLQRInyqmiriqLo1PVbmFZDt3ad11w4glvXaCzazEOkwTS2XLGssU4Fls9tue6SJvPHb2iBR88ylRCjakENYt5LWP6d9NVfEbp1pcZhOpWKaJTezMINu%2BFPA4G84C81iB3Jq9CvNOTK0nQ25cw4NNGL%2FMpDGYYBduDLkne1rRBl%2Fc8LzzioA0k1nVjffi0gV1iajCZNtga30OnDbp8speDt31RpGIxUaS6amhTFGkLRtxVSjbsOgaJDQSSCo6qUaTBXogdgFrTKHx2xuq4yDv3sdgJrjOHNzNmX1V463eL4aefvq7lES27anfZNaUaK19dWebMMCNBkYT0gYpsZEyp9ka1qsJ3lEknqD6Ay0awTTlBqsI7uetJp0C4uPNS9qI0gLyopnXP1OYzVvc%2FIZgKCpxkSeuW1psZEKxrAtRFE%2Bo0VtGqanxCWtJ8F5p3K1twEeDN0VywCJakec0011vIc77oRfJ8B55HNGozzwUrAh2S5%2Bmuq6Miu8ZWKLSA7LwXL8m%2BC9k3r0bTArLzKZj782BC69WlTW%2FGdRfl3fbMcj5gkyzfheXVS0r2zHI%2BVns%2BIMu%2FjkVvAdf5yhLJ9V24Xn0A2p65zrtw0qI3HKUfnuZJ556keU0037wkfQtozvtwHM7tmlO0hbPe5iZdG5gc1ODmj0qchcpTkDOlJNqeBySoaomJA6XsFcleXm6gAdljlmPQ9c8qecmrH7Xk5c6%2BfKqaRqeFRXqrrqHCKr24TGAvQq%2BywZixrdQXTevcuNTzGXnq8swnodskQ%2Fg6fXt25u2yK9c06NrzOk%2B69qXg38SmFrv2giVeLtBkimZ02SgFDTdZvLhyPFVvnrJ9WsLq5GjHBRPkO69j12cIrxpJQ8pSpo0fwWaMRsgHXsYC7rICnLAs%2FdAGT7xwZmlzl1O7tatpYxw6g103q%2FTacKy6Yy9UU1W6xixSY6nqZpPLHh8%2FZ34Z%2By6Hq2caw9omqt51PjH3jXw%2FIm7Qg4NoPrDPwe4qg06a9j2jkZO1M0xnIh2LvURp55GZPUAtufZMZYax91EKGJbzXM1yQDBZOXEHBRNWy8kMavRpWVkuO%2FJjFdfV7%2BMIpi7PzpN37ryTV54HMEjNlvcKQe5689LlLaJdi0eHCOZFvkGeI7GuHeuDT3WgGuVXnZcjgaoDXHZug8ZGAhl8SdkTWD6Tt5L5igbwFs1tvmdCC1aLCyDAUbqCRjWgQ71NdjHsB7gg7Tdgwucw6x8vv86pa5WWmW9jzLPyngrnVsvJtu8aHDEJcWvb9AObbeUuVFdwxDywre5jmLshmMnp%2FpU0XN6e3zyf35Nfd1c3Vw%2BXPDXEK8f3AF1TXrmdTD04IaIEoqRB8clJC9GDfoZo1r9zFB66Wk%2F%2BZBBp3HMqJqP%2BXxqNAajmI%2F81OuYr%2BW2Yf6%2FPTz%2Fl1Qe5yyxKZ9w6EOQ%2FDvms0RMlzWwQOAZTGCp%2FTJX%2FYuxi%2BEJUOW1bBGCaTYWs3%2BFxjiMHIl6sPXh7pAYAh%2Fw8VQRzYDUVebFL2BpJbjetrbsCbc0SoYS2JpsBomishZh8o%2FE9ciA94v8%3D)

This diagram shows the structure of our program. Room and Entity are abstract classes that contain information that each room and entity would need. Players and enemies extend from the Entity class while combat and interaction rooms derive from the Room class. Room class has one function, interact(), that is used for all actions within the room, and the derived subclasses define this function. Entity is a bit more complex - the Entity class contains various fields such as attributes and health values that all entities will have. The Player class is unique in that s/he can level up and hold items, while the Enemy classes provide rewards upon death. Map contains a vector of Room classes and some global information. The Item class dictates the player's abilities - the player holds a vector of them and they passively affect his or her attributes while also providing a list of additional abilities. The Player may also recruit allies to help with his or her quest, which will be handled by the Party class. 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
