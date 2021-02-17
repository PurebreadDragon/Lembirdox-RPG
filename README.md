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

Class diagram: [[link]](https://viewer.diagrams.net/?highlight=0000ff&edit=_blank&layers=1&nav=1&title=Final%20Project%20OMT%20Diagram#R7V3ZcqO6Fv0aV5370CnE6Dxm6nSfm3Snk9weHhWj2Jxg5ANyHPfXXzHZIAkzGAxxqyqVMmJm7bUnbUkj7WL%2Bdu3DxewW28gdqYr9NtIuR6pqnur0f9iwjhvGwIobpr5jx01g2%2FDg%2FEZJo5K0Lh0bBbkDCcYucRb5xgn2PDQhuTbo%2B3iVP%2BwZu%2Fm7LuAUcQ0PE%2BjyrT8cm8ySt1Ctbfsn5Exn6Z2BeRrvmcP04ORNghm08SrTpF2NtAsfYxL%2Fmr9dIDf8dul3%2BfF5%2FcO9eTGv%2F%2F4W%2FAv%2Fd%2F7fxy%2FfP8QX%2B1jnlM0r%2BMgjjS%2F9%2B%2BX546fv%2Bj8%2FF3cfv62U67Onvz8kpyiv0F0m3%2BvKIw5ZJ29M1ulnDFbO3IUe3Tp%2Fxh55SPbQj3AOXWfq0d8T%2BnTIpw2vyCcOReAs2UHwgrZOZo5r38A1XobvEBA4eUm3zmfYd37Ty0KX7gK0ge72SSJMqpk74iE8kzYrtNVHAT3mLv0wYNN0AwOSHDPBrgsXgfMUPXB4yBz6U8c7x4TgeXohvPRsZCdbG6SjDeLjl43shOdXhCOBLfwa6C0jjAk81wjPEfHpp1aSvZqSwJFQzUglb7UVXGAmbbOM0NLWhDAJWaaba29ud0%2FJBb0p%2FQib%2B9Eb5u4H9Kr3Y24HXQq8Bwk6Dz9jkBVD%2BiPzqtumSDhrCCrgBPULnCNOTOmXJhmRdNEzKRTIYAEnjje9iY651Lct98mbhk2YnvvsRsIwc2wbeZGwEEhgLE%2BhhCyw45HoUxjn9I9%2BsAvlxBgZ9IEu6DbYbtO%2F8HCfXGCPyhV0IgFCVFhXKBRYgWjtpG25aK3ziNVFNitIOUh34OddBF9WbzcE%2FHx5dl8%2FzrR%2FIREomjNCfOdpSVBwdCju0CYzMneTnwUYVoW%2FEGtDPRzWwsdTOaw%2Fe6%2F0jbDP25U%2FCer2aW2Ne4Za42n95LgOcf5wVrcPNVD0nlU44MG%2BRMHEdxbEwd7Rwd2VegZaQy%2BrNSBVnWftJMTwe9QggawIpHFAp0r4fDyOHHiuE8VsiYICwnimBNk5xSi8XArlY4j05QfAwa3xcGsCaF34hNw7HDiR2tAu%2FfhYBvK%2BPGUwrug%2BjTtip8GT8%2FmZBm%2BfEA2zZn%2F9R%2FKzKj9PD6hohc9n8lDaoSO89JHPwViQYVFkhqW9DMtGJNJkZipqZSICtB10L86wACbDoo2Hm2GxOGG9cGFwfG58Rd1iVpatoaRY%2BBTZDXoNk%2FlHCWATe2HuBLD3vMmpdOdaZ2XVDEkL3pw4b13AyuXiaD259kEc965aNZ6bccgcHC2M7StYAPrWsOkD7FKxyLPPwn5nuvXk4tARPqdNiacMlHjzo%2BOmCb8SVzbv9yJ7ilLPHrlPeHW1bTiPGuiOVFJqO8IBXvoTVM486vpPUYWoOXzanfwUAekjFxLnNd%2F9vsNtvgsFd%2Bsyq%2BO8y2wqWv4S8UsmZ23lof6F4q%2FAXai1Hks%2BXXrloXnlrnUZ%2BLUY%2BOlK48DvtFSCBYGfplcI%2FKxhBH6ATyPeoxX07aufd0dq20oN2Ya87yf849VNjOIt9tDx9bs291FiaAcRBQpx5PMwkdl4XC9k10xlFA%2FZMS5EccyhGAJ4i23n2REkfyWQQ%2Bj2Fj8g3yHDwfenp2Xqm8vKveCdJWb4zhkO1mMOBVPIBh0LMt01ltUwFtSYC5kW8yxdx4K8Ub%2FHNEKqGArKKusWQ0HTYKqeQUVN1LAP0GDvN%2BQqa95tOf4Sr3LrZlWWsR6CQXEJLl9v%2FYWCJVQ67x3FVusy62Pdf8DIR%2F4%2F4vv%2ByUg3ikWsnUj3Xm2t8khzGP%2FxoUhtAlcOMTur%2BONhfXV8soTRmaG7ByekuJ8xxvcCu5i6hZcejt1HGpUwTe%2BW9p0R%2BqAdkuKOZd7hukYeBVw0LCrDaRa8p8TNPs%2BErHgRAWPDYBbpTJALX8fh1ptDfiZ4hb9%2Fhb8pKPHW5Vtm1%2BU63fDoe0cnnVhGuv0ru3N7XrSVnjgShZHNAlpx%2Fjv5lKUBbVHGac9g1VDGOT9f1az8JZoGq2oaQJQEqxR3uM4cljCw%2BIHV%2FH001WDkOb5i0whDPPZA5QT%2BA92Mi5tHqumGhH%2Fy6a9p%2BCvcdzdbB2ckikcL91%2BiZ%2BQFSHzALZzuOp%2Fu3nn6wwJR%2FnCh%2BgwuUKRcSahcVzOHoAeqKsO2lQ8XeRv8RO8%2BjdyXr0sSm%2Bio3Yb%2By9dQwZKIJidKSKkgSTCNeaVdSRUW06gwKGZEzhDFqLpAMZ4yotneGJUKrk5G1yUmLqfrMp8%2FbL%2BDJIyfoxZV0TjHSM0pt5xmOzFKdFuqSMGJolh1lCnduEO%2BQ79ZmNM5iJ5MP2RWTxYP2d2Z5zMEEmG0lPpjlNMYMJJWuQzEYnKIZjVt2pbC03iFt0uQ%2B88zb5yCjez%2ByopumVOQ8wlAzz6BblT1CQocxQ6S2mOTMe9js5lkjxUjd6FNPcmhJLvC8LNhSXZDKW3CiM69XWt4km0qLUm2xXqm4wNLdoUuXynZzSR7SAJraW0JLNPHo5ud1Zru1AbZwVt4%2FgTFCf8dBaf7dR8Kkk41exTjplv4ljuwbj%2FjqKMoydANsbxkZTOtF8llDjsr%2BuPzR2G12I7pN2S2sIRFtTr1RGB3lizU5QCxDmAV9d8JOdwRqqnpyKAqc%2F7dwW0KMluHZTE%2FIvCrbTtkLW11m7batNSToVlrnc8FxdBLmtemuV6%2FAuegNDdk2XAHsPZurPmqYWmsu4O7f2PNs%2FhqvpC2ul1bPS5KHJbhnqqD9nnO57Ylz%2FfhuTFsa23yPP%2B2DF%2B6IsezlnpIFfrD5r3OjJK2BOpeWIlv6l3JAW%2FfKxTAS%2BKXEGsQhfLi5%2BNzaq9oQihqSS1QbOnjaqBRWCy0kFLQthT0X0LP52TOcfHcdxLppkj3Pi7b4lMw8TQJEuu2se5%2FxnKT7xblYE5yMHzipT7Gx5aLKcP3gEO4xc9XXDwvg7Qu8O5defNdZRzMnQ2SAKMGgyQ%2BKCcK2FQWx6eCcWlZTrh16Lrg1BNuXKCzbzEOkwTS2HLGqsU4Jls9duC6SIvPHT3iFR88ylRCi6kEkMe8lTH9%2B%2BkqPqP02ZMZhPpWKabTcDMIFu%2BFfJ1Mlj59rUnhjF0S76Z4958r4DNGD8sF8gOCfYl363j3njEY807nhUt9s4nEum2s%2B88YWBVmBZMZg8b49p0xGPN5Xg7e4QWQiskEkGDTMKQA0hIMtquVZ9h3%2BBEbA6TFG3UDSJ29EDv2tKUB%2BOyk1El9d%2BFjsXNY5w7vZrg%2BUHjr95mgdz9z3cCDWXZh7qrLRnVWubqxzLkRRoL6COkDldnIhFLDDWiBwveRSSeoPYCrRrBdOUFA4Z3c7XxTMFq%2FeS07UDpAXlTOemBq88mq2x8ILgS1TbKataH1ZsYCa6oAddFcOp0VswKVz0VLmu9D83FtCy4CvDuaC9a5kjRvmebaAHnO17tInu%2FB85hGQ%2Ba5YNEfyfN2ea6ydQkD4DnvwEue78Pz3WvQDIDnfPbl9syfh1XqkubdeO2ilNuBWc7HapLl%2B7C8fiHJgVnOh2n3kuXdGvMB0JyvJ5E034fm9UecHZjmvPcmjXnHsXn%2FNE%2B79CTNW6L57rXmB0Bz3n3jcB7WJKIDnOa2MNXawWygOjdhVOos1J5znCkgUQ88AgGACjMFStkrk72itEAHssesv6Bp71Xy0lc%2FaskrnG75BBj6aICleZsOodLavKQ44CBCD9hgTG8q9WXzOHcu9XwePnR5lvPIbZJufTc5Or3qKjUdevW8upNefSX4dxFpwF69YDmXCzxf4CBcIkrBz7uMXVIqnikwz5g9NSV0erTtwDn27MeZ4zFcB3rakDGSWbtHsZnhKfagmzN%2B%2B6z2JqxD79vWiRfJrGzpCoq19rVqjC%2Bns2tkVV4HjlV37IVaKkNXmQVpTAB2W1v2%2BOQ5i%2BvW9zkcnKoMa7soc9f4nNwn%2Bv2ouCEXTeK5v94Hu%2BuMMuna7YyHSrbOMI0Jckz2EpX9RmamAFBxnZnaDGPvo5QwrOC5uuWAYGJy6g4KJqeWExe06NOyslx1qMcmpGvfxxFMU56fE%2B%2FMfqWvvPSRn5kZ7xHBwrXlpctbRrsBDwcRzIF8jV1bYt061r3PbQD06ivMy6E%2F9QGuOplBZ0N%2FdL6Q7A6u7%2BlbyXxFB3iL5jE%2FMKEFK8P5CJI4XRFGNXAUepvswtdf0Iq2X8M5n75sf4D8Np2u1lpSfogxz8Z7Kp1HrSDRvm9wxOTCzabpBzbbyl2oreCIeWAL7DWunW76GJPs4T5czG6xjcIj%2Fg8%3D)

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
 
