# Hanging Pointers of Babylon
 
Authors: [Raymond Yuan](https://github.com/raymondlyy), [Shawn-Michael Kern](https://github.com/PurebreadDragon), [Jane Ran](https://github.com/jran26), [Zinal Patel](https://github.com/midgetdemon)

## Project Description
We are making a text-based dungeon crawling RPG. The player progresses through different areas, fights various types of enemies and becomes stronger in an attempt to reach the end of the game.  
* Why is it important or interesting to you?  
We are all epic gamers that appreciate gaming and as epic gamers, we must make an epic game for this project. This project gives us the most creative freedom in story and design and allows us to utilize new aspects of C++. 
* What languages/tools/technologies do you plan to use? (This list may change over the course of the project)  
C++, nothing else planned at the moment  
* What will be the input/output of your project?  
The player will interact with the game through console/text inputs and the game will output a written description of the result of the player's actions. If time permits, we may update it to produce images or simple animations  
* What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:  

Composite and decorator. For the composite pattern:  
   * Why you picked this pattern and what feature you will implement with it  
   We selected Composite for easier implementation of similar objects (making enemy types that derive from a generic Enemy class, for example).  
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want to have different types of rooms and enemies within the game, yet we want to be able to interact with them in the same manner. For example, we may have two different types of enemies with different appearances and abilities, but attacking said enemy should deal damage in the same manner.  
   * Why the chosen design pattern will lead to a good solution to that problem  
   Subtypes of rooms and enemies will derive from the base class and inherit some global actions that the player can perform on them. This saves time from having to rewrite the same actions for each unique subtype we want to create while keeping the results of the player's actions consistent.  
   
For the decorator pattern: 
   * Why you picked this pattern and what feature you will implement with it  
   We selected Decorator for more efficient addition of unique attributes to special types of the same class (making enemy variants from the same type of enemy, for example).
   * What problem you anticipate encountering when implementing your project that you will solve using the design pattern  
   We want to have special variants of rooms and enemies. We also want to give additional attributes and features to the main character as he/she progresses through the game.  
   * Why the chosen design pattern will lead to a good solution to that problem  
   We can "decorate" enemies and rooms of the same type with additional features while keeping others the same. We can "decorate" the main character with extra features from the items he or she picks up over the course of the game.  

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
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
 
