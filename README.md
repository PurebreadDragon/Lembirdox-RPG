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

We will be using Composite, Factory and Strategy. For the composite pattern:  
   * Why you picked this pattern and what feature you will implement with it  
   We selected Composite for easier implementation of similar objects (making enemy types that derive from a generic Enemy class, for example, and having all things in the game be Entity class objects).  
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want to have a large variety of entity class derived-types but still allow the player to interact with each of them in unique yet consistent ways. 
   * Why the chosen design pattern will lead to a good solution to that problem  
   Using a composite structure of subclasses derived from one master "entity" class saves time from having to rewrite the same methods each time for every new enemy type. On top of that, this keeps the expected results of common actions consistent with other entities. This design pattern can be extended to the "room" object as well, where one master room object contains some basic functionality such as "observe" or "search" and subclasses such as battle rooms, trapped rooms or loot rooms derive from said master room object. We can use this to achieve runtime polymorphism by calling the same dealDamage(), interact() etc. methods on those objects. 
   In this pattern, the Quest class is the component class, which contains an aggregation of Room objects. Room is a composite object from which CombatRoom and OddityRoom are derived from. 
   
For the factory pattern: 
   * Why you picked this pattern and what feature you will implement with it  
   Random generation of quests is intended to be a feature, so we need a factory to create many different objects (items, enemies, rooms) based on various critiera (difficulty, rarity etc.) and link them together. 
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We need to create many objects with unique definitions in their own files, so a factory pattern is ideal for doing so. 
   * Why the chosen design pattern will lead to a good solution to that problem  
   We can have a factory class that keeps track of and manages all different types of items, enemies and rooms we will be creating. It allows for unique generate() functions that we can use to generate a large amount of random objects to populate quests with. 
   
For the strategy pattern:
   * Why you picked this pattern and what feature you will implement with it  
   As this is a game, the player should have many options to choose from. Options in combat, options in traversing rooms, options when resting at town. 
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want the user to be able to select a strategy for their player character at runtime. 
   * Why the chosen design pattern will lead to a good solution to that problem  
   We will create various strategies and allow the user to select them by interacting with the program. 

## Design Documents

Class diagram: [[link]](https://i.imgur.com/qC7CEW5.png)

This diagram shows the structure of our program. The Composite pattern consists of Quest (the component class), Room (the composite class), CombatRoom and OddityRoom (leaf classes that are derived from the Room class). The Factory pattern consists of Generator, which generates the three types of objects - Entities (enemies), Rooms and Items. The Strategy pattern is implemented in Adventurer, where the client interacts during runtime with the class to choose a strategy during combat.

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
 
