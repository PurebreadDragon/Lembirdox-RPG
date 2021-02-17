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

Class diagram: [[link]](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1#R7V1bd5u6Ev41Xuuch2RxMRc%2FxnaStidJ06anac%2BbDLLNCUYU5Djur98SFxskGYMDNknYq2ttM4ibvpnRzKeR0lNHi5frAPjzW2RDt6dI9ktPHfcURZZNhfyPStaxxND7sWAWOHbSaCt4cP7CRCgl0qVjwzDXECPkYsfPCy3kedDCORkIArTKN5siN%2F9UH8wgJ3iwgMtLHx0bz2OpqRhb%2BSfozObpk2V9EJ9ZgLRx8iXhHNholRGplz11FCCE41%2BLlxF0aeel%2FfL4ef3o3jzp11%2B%2BhX%2FAf4f%2F%2BXH38yy%2B2VWVSzafEEAPH3zrv0%2FTq08%2F%2B%2F%2F%2F5d9ffVtJ1xeTL2fJJdIzcJdJf1162MHr5IvxOu3GcOUsXOCRo%2BEUefghOUM6YQhcZ%2BaR3xZ5OxgQwTMMsEMQuEhOYOQTqTV3XPsGrNGSfkOIgfWUHg3nKHD%2BktsCl5ySiYCcDnCiTIqea%2FFAryRiiUgDGJI292nHyBvRDQhx0sZCrgv80JlEL0ybLEAwc7whwhgt0huhpWdDOznaIB0d4AA9bXSHXl8SjgQ22hvwJaOMCTzXEC0gDkhXS8nZjaYlptbvJ8erreLKeiKbZ5SWSBODSYxltrn35nHfiXEBb0Y6Yfs8Nf88ufTzmMcBlwDvAQyHtBvDrBqSH5lP3Yoi5aygqDKnqHdgATk1JT2NMyrpwineqZChDyzHm91Ebcb9reR78qVUhMi1UzdShrlj29CLlAUDDGJ9ohriI8fDUVdoQ%2FKPdNhIOtd6GnmhETmWt8fkH20e4BHyiF4BJ1IgSJR1BanCClSr0Gz3q9Y6j1hVZLOKlIO0AD9vFN6tXm6w%2FOtp6j5fzdU%2FAAsczQXGgTNZYhi%2BOxQLvMkcL9zkZ1NYa8rxsBa%2BscIPKn%2BWjr%2Bg39lBXSfUhnliqFXerCeO62Cns%2BqaoZal%2FolduMyDPYahFTg%2BdpD37uBuDEj1wCirNiCVPm%2B1FsXwZyTogCwJpHbEoEr4yjyOHHiuE%2BVsiYOShfnMHmQXBCN6uxTKHxTp8ZnMwa3ycKsCaF0wge49Cp3IbajjIG7LQH4yVFPCYx%2BqZkPWqfHGOZ2S5O0TJGnW%2FF%2F%2F7uyzLJKDIzpa4SvrHJT3LljDYDQHAbAoWVKSZpE6mqU%2BmkWW87SH0ZfL6YmsFtj8bppFZmgW1WwvzWJwGjtyQfj%2BYvmSPkcvrVtt4Vl4nuwGPlNKvwPwbZAngy6mqx3UsjRJDSGdmLzeYZVL%2F%2BOGc5VBNE%2Bdbck8r8mBBz37gk5akqOJi2gANSSiJMKSpfjwynFTtmhPCJSPl6A9g2lECN0JWl1uBcNIQE6kilI5gArRMrDgfsRIyDiDJQJ1%2BraFuIqADKALsPOcn7stCLfuqd5uQy1FyodamqLmbxF%2FZHKVkpksrXqjuBe4G9U23cVzbZceXJSel%2B0ShhoTBlU5OGEY7NVgQcKg9kskDEY7EgaZ56C%2BwxUI7Mtf9x91aNsY79tJG3h3E6N4izzIO50OxxZkD0Ic%2Bfw9GjZ%2BrP0Py%2BtXR%2FGYs6pCFE0ORQrgLbKdqSMgDTsg2zBnKn5nns3n4Pvo6fwBuJadQm0soeeZfQ7W95wKppC1OhdkaH59cGAuqDI30gbMuzSdC%2FKD%2BndEMqSSqWBXoltjKqhrTMmsXNITHTh3pLHPa3OJLh%2B2dPVBW%2BttZTIort%2Fki3XvCFhCp%2FPWUay1qK861qdPGPnM%2FzF%2Bbod0rUifvFRX4ZHmMP7wqUhlWEunmI2Vi%2FGwPjsBXoLoShruAQvvnmaM8R0hF5GwcOyhOHwkWQkjerNm3xzy8ql9tyDguoYeAVy0piZj0yx4kyTMHmZSVuRHwNggnEc%2BU86lryY9enHwrwQv%2Bvs3%2FU1AiY%2FGL5lT43V64JHvji46N7T0%2BHf25Pa66Ci9sFo8n81fxXR30nN789c00d2bwL4yWdUkMxfnK6qRv0XpZHWQTxiUNIHYk6wS3ME60yyxwJ0v3GfnqBSN0ef4jodmGOLCdYVT%2BDNyGFfG9hTdpQY%2FCcivGf1Fz93P1%2BEFjvLRnefHcAq9EIob3IJZ0fXkdOHlDz4k9sOl6nPgw8i5YupcV3MHwwfiKqlsFQA%2FPwZPyNNnUfjydYnjITqS2yB4%2BkodLI7M5FyiJhUmBJPJO%2B1qRlShoJJZtqoLctS%2BwDEOGNWsb4FDiVAn4%2BuSIS7n6zLdT%2BX3ANP8OZIoksoFRkrOueU827m2x7eljlQ%2BlySjijMlB%2FcwcEifUU6nCT%2BZ9lvWTxYt76zC82kCjdDqof5kxjkZKqNpZb2pzHhT3SznTetyeCrv8IoU%2BfQ88yYo2Oju76zq7gsKcjGBfNyYoK%2BVjQmM6speF6lt6szwbuqHabYpabkbbepJjqXZJdYutUuzD9TSQyyi7mjXeAOarUs1abbBVGupx%2FbZJaZ8O80updmtVlhDrUthNTZ%2BbqzWtNA9ZBf9oMUEiAn%2FgoLT100fCkinijOKsegWvOQaVp1nrKai5bMkra%2BJ9SWrm2m9SI45bKzoj%2BePaLVYwd4NH5AtLDaZV03qicBujCzsdwuLGoBVNH8ntOGGUE2HjgyqHeffHNwiZuu4VsyvJPtq2w5ed2N1nWO1bijnbRut%2BzwXFEPfmXmxmffLw9%2BWwVrryoYbgPXkgzVfNdwN1s3BffrBmrfiy4XfjdX1jtXmLuJwH%2B6pO6jfznluu7Pz0naulVaAtozWOm%2Fn35b0o0vaeHakblOFfrvtnq1AMQTuXliJn25gX78e8ON7iQL4zvAZK2plobz4lXlO7RlamKCW1ALFI31cDdSjxUJ%2BpwV1a8HpS%2Bh5TmaIdu%2BZ1iF9KNInX5dt8BRMvE1Ch3XdWJ9%2Bu2udnxblYE44GJ54qY7xm%2BZiDsD3iEu4xa%2B8u3i%2BS9KawPvkzpufKuNgbmyRhNw7YJHEmXQuyZvK4vhS2dxblkOPGq4LTgPf%2Bgp0XluMw5BAKlvOWLYYR2erx45cF2nw3NEPtOKTx45KqJFKYBYw1LKm%2F3W%2BimeUPnsdg7BnVNrYztthEAw%2BCvlqWcuAfKm1c8euDu9D8T49V8AzRg9LHwYhRkGHd%2B14n5wxMPmgc%2BSS2MzqsK4b69MzBkaJXcE6xuBgfE%2FNGJg8z8vB274EUtKZBFLeCE6YQBqCxXaFTEPTCaTO5gDpPHTVBLLP3kgul0BWXoDPZLxJfffO12Kam7nmzSzXN0v4w3YZDLNyW9m3dLtuqxgcR9llM68MGrNNeeld8rnEWT5nzKayttdNqJg8jf8gDLYLtk%2FsCrCK2BNWC0R%2Fdk20%2FUNR%2FVXyMNEfLd%2F%2FtOPvhyjWPD63J5pnPUH7M4aLbn54T4Ro1rLGSqR4dSQAt4uR9gQer2%2FANfx5jWz4Bf1P8EfOKdJlPc17K%2FXkgCvrfHbztOzmRqLdUEWIb3LD2iHnd5q5Awu6F1Av2jc47YsPa%2BZ7lGC3GbXXyvk0sKvyaw5uEWV7VLgVDu4LjANnsqSxg7f86ON4%2FYiLSNujIl5ta5q6dg87ZOckwQ5gh%2B5C1hNlng1vJbbb3njlONLOYbp0PjCl7X9KLuDQ5ANZITbjVhtihdjHqDJjDZVoHnIYIISzzQPgz28JUrTFPw%3D%3D)

This diagram shows the structure of our program. Room and Entity are abstract classes that contain information that each room and entity would need. Players and enemies extend from the Entity class while combat and interaction rooms derive from the Room class. Room class has one function, interact(), that is used for all actions within the room, and the derived subclasses define this function. Entity is a bit more complex - the Entity class contains various fields such as attributes and health values that all entities will have. The Player class is unique in that s/he can level up and hold items, while the Enemy classes provide rewards upon death. Map contains a vector of Room classes and some global information. 
 
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
 
