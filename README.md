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

Class diagram: [[link]](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Final%20Project%20OMT%20Diagram#R7V1rc5u8Ev41njnnQzIIzMUfY%2BfSvidp06anl48yyDYnGFGQ47i%2F%2FkhcbECyDQQMdZjJdKxF3PTsrnYfrehAmSxf73zoLR6whZyBLFmvA%2BV6IMvaaEj%2FZYJNJDCAHgnmvm1FIrATPNl%2FUCyUYunKtlCQ6UgwdojtZYUmdl1kkowM%2Bj5eZ7vNsJO9qwfniBM8mdDhpT9siyzit5D1nfwDsueL5M5AG0VHljDpHL9JsIAWXqdEys1AmfgYk%2BjX8nWCHDZ2ybj8%2BLj54dw%2Fa3f%2FfAl%2Bw%2F%2BO%2F%2FPt0%2FeL6GK3ZU7ZvoKPXFL50n%2BeZ7cfvg%2F%2F99N7vP2ylu6upv9cxKdIL9BZxeN14xKbbOI3JptkGIO1vXSgS1vjGXbJU3yEDsIYOvbcpb9N%2BnTIp4IX5BObInAVHyDYo1JzYTvWPdzgFXuHgEDzOWmNF9i3%2F9DLQoceAlRAD%2FskViZZy%2FR4YmdSsUSlPgpon8dkYMBWdA8DEvcxseNAL7Cn4QOzLkvoz213jAnBy%2BRCeOVayIpbW6TDBvHx81Z32PkF4YhhY6OBXlPKGMNzh%2FASEZ8OtRQf3WpabGrDYdxe7xQXaLFskVJaKo0NJjaW%2Bfba29t9pcYF3TkdhN39lOz9QOH75W4HHQq8Cwkas2EM0mpIf6RedScKlbOEogJOUT%2FBJeLUlI40Samkg2Zkr0IGHjRtd34f9rke7iRf4zdlIkzPnTmhMixsy0JuqCwEEhjpE9MQD9suCYdCHdM%2FOmAT6VIdqPSBJrQNdm36x7r7ZIJdqlfQDhUIUWVdI6awAtU6aLbHVWuTRawssmlFykB6AD93Enxav94T8PN55rzcLpTfkAgczRUhvj1dERScHYoHvMmCLJ345x4Mi8K%2FF2tVPh3WwseT%2BUnl98r2luyl3jPU9Zu1brQMtcKb9dR2bGK%2Fc6uuH2ogDVt24YAH%2BxoFpm97xMbu2cHdlHsGSsUoqzYg5SFvtSbD8Hso6IEsCKR6wqBK%2BHw8jhx4jh3mbLGDAsJ85giyS4oRu1wC5TeG9PUF4OBWeLgVAbQOnCLnEQd26DaUaz%2Fqm4O8rUgZGAXDJ6Mh61R545zNaPL2AdE0a%2FGvf%2Ff2WdQ%2BRyd0tMLn0zgoHx24Qf5kAX1oMrKkIM0i9TRLfTQLAFnaQx%2BCYnoClAM2v59mATmaRTG6S7PonMZOHBicXyxf0MFohXWrKzwLz5PdoxfG6J8lgFUmDe0ggK2TJ6M%2BpqvdKovSJDWEdGLyeo9VrryzDefqB9FoO9sCPK%2FJgYdc64otWtLW1MEsgBpTURxhASlq3tpOwhYdCYGy8RKy5iiJCJEzxeubnWAcCuiBRFFKB1ABXvkmOo4YDRnnqEDKxZ72IK4iIH3kQGK%2FZNduD4Rbj0xvd6GWLGVDLVVWspeIXjI%2BS04tlpa9UDQK3IVqW%2B7iubYbFy0Lr8v2CUONCYMiV04YRkc1WJAwKMMCCYPejYQB8BzUV7SGvnXz8%2FG9Tm1b4%2F170gbe3UQoPmAX8U7nPHCskjxE0HYiexDiyOfv4bTxbeP1vH5hFE%2B5qipE0eBQZAA%2BYMue2QLSsAeyC2um4gfk2XwOvveezpefLgsvoTaW0PPMPgfrOaeCCWSdzgVzNL82qpgLKrkLqaPcszSdC%2FKT%2BldMM6SCqWBfoltjKqipuZJZUNATVVw7UvP363KJLh%2B2nH990PHZTS%2BsYy0kg%2BL6Tb5Y9xMFS%2Bh0%2FnYUay3qK491%2Bwkjn%2Fn%2FiO77npGulIvoB5FuvVRX5pHmMH73qUhpAy6cYjZWLsbD%2BmL7ZAXDM1m4B02yf5kxwneCHUzDwmsXR%2BEjzUpyor%2FW7BszaADa9t2CgOsOuRRw0Z6alE3nwZvGYfY4lbJiLwTGgsEi9Jkgk74arPVqk58xXuz3L%2FabghK1rl9Th643ScOl7x2edKmrSftX%2BuDuvLCVnDgQpZHVElox%2Fx0P5dGEdh%2Fj9MZkVZWMTJwvK3r2EoWT1VE2YZCTBOJIskpxh5tUt9gC9z7wML9GJas5fY6uWDXDEBeuy5zCX9BmVBk7kDWHGfzUp7%2Fm7Bc79rjYBFckzEf3Hr9GM%2BQGSNzhAc4PnU8PHzz9yUPUfrhUfQE9FDpXwpzremET9ERdJZOtfehl5%2BApvfs8DF8%2Br0g0RYdyC%2FrPn5mDJaGZXErMpIKYYDJ4p13IFe43o%2F0Flbltq5ogRx0KHOMop5r1bXAoEOqkfF08xWV8XWr4mfwREpY%2FhxJZUrjASM44t4xnu1SP%2BLbEkYJLSdLLOFPaeES%2BTceMcTon8ZPJQKb95P79ngd5PlWgEWo91B%2FIOSddyWlaUW8Kct5UM4p507ocnsI7vEOK3D7PvA0Ktrr7K626x4KCTEwAWo4JhmrRmGBPoNgAqW1ouend0KpptiGpmQtt60lOpdkF9i51S7MramkVi2g82tW7p9maVJNm67lqLeXUPrvAkm%2Bv2dU0u0sKqyt1Kayaj58bqzU96A3Sm37wcgrFhP%2BBgtO3LR8KSKeSK4qR6AG%2BZjqWXWccNJQlqUNVrC9p3UzqRTLMYWNFfzx%2FxKrFDny7oWcLj1hRqUU9EdiNkYXDfmNRA7CK1u%2BENtwQqsnUkUK15%2Fybg1vEbJ3WivmdZJ8tyyabfq6uc67WdPmya7P1kOeCIuh7My9t5sPyFTgnNXO1LxtuANbWJ2u%2BarifrJuDu%2F3Jmrfim6XXz9X1ztXGPuLwGO6JO6jfznluu7fzt9i52u3ZWuPt%2FMuKvXRBG0%2FP1F2q0O%2B23ecrUHSBuxdW4mvDpvSAn98LFMD3hn%2FEsDpRKC9%2BPp5Te0EmoajFtUDRTB9VAw1YsZDXa0HdWtB%2BCT3PyYzx%2Fm%2Bm9UhXRbr1fdk6T8FEn0nosa4b6%2FY%2Fd63xy6IczDEHwxMv5TE%2BNy7mGL4n3MItfr79xfN9ktYE3q07b36pjIO5sU0SYFBhk8SFdCmBbWVxdCowjpblsNap64KTSLhygc5bi3FyJJCSL2csWoyj5avHTlwXqfPc0Te85pPHnkqokUrIbWCoZU%2F%2F23wVzyh9dHsGofysFJlTdxkEnY9CPpvmyqevZe79YlePd1W82%2BcKeMboaeUhPyDY7%2FGuHe%2FWGQODDzonDo3NzB7rurFunzHQC3wVrGcMKuPbNmNg8DwvB2%2F3EkhJyyWQYCvoUgKpCzbbleIZ3rr9KJ8DJMUbZRPIYf5CoFgCWXoDfi7jjeu79z5WrruR6d7Mdn2jgD%2FslsHkdm7Lx7ZuN24Vo0aUHRhZZVBznykv%2FJV8LnEGlzmzKa3tdRMqBk%2FjPwmD7QOfT%2BwLsA6xJ3ktEP23a6LPPxyqv4pvJvpPy4%2Ff7fTfQxRrHp%2FbU80zn5H1kaBlvz5cPkI0yu%2BxEilehQSANn2MSVpBfOgtHrCFWI%2F%2FAw%3D%3D)

This diagram shows the structure of our program. Room and Entity are abstract classes that contain information that each room and entity would need. Players and enemies extend from the Entity class while combat and interaction rooms derive from the Room class. Map contains a vector of Room classes and some global information. 
 
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
 
