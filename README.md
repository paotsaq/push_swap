## Sorting algorithms are fun, they said...

...but maybe I just grossly misheard the spoken words, because what a hell this was to get right.

### Did you not enjoy the project, Alexandre?

I did enjoy many parts of the project, but I feel with proper technique it would have been done *much* sooner. Some points to notice:
- test-driven development is a life-saver, really. The amount of time lost by changing code, working further, to just later realise mistakes were introduced...I shudder just thinking. 🥶
- learn proper Makefiles. Having a rule to quickly insert the user in a testing environment is *very useful*. 🧹
- breathe deep, and very slowly, as advised by [James Nestor](https://www.mrjamesnestor.com/breath/), and pretty much every meditation practictioner out there, and way back.

### But now, please suppose I am a struggling young mind, needing some orientation in this project. Presupose despair. Maybe some tears.

🎉 You can do this! You're the best! 🥂

Motivational emojis aside, my strategy was good enough for a clean 5/5 - it would probably aim for 6/5, really. Most of the project was done with the precious collaboration (will all the very fun and provocative insights along) of my friend [Michele](https://github.com/mikysett/), and we both set on the idea of using a LIS - stands for largest increasing sequence - as a starting point. This was mostly due to being an **amazing** starting point when the stack was already very close to being sorted 💥 but with no logical step in any other scenario (which is, alas, much more likely to appear).

From then on, things got harder and blurrier; we tried finding LIS in a recursive manner, hoping the merge of LIS would be easy to handle -- and efficient, too. That was not the case. Having the LIS in one hand and shattered dreams on the other, [dmalori](https://github.com/demian2435) came to the rescue, providing some orientation for a solution that relied, but wasn't solely comprised of the LIS.

### Suppose too I have no time for historical recollections -- give me the facts, Alexandre!

Alright - so, long story short:

- obtain the LIS of the unsorted array. There are many algorithms and approaches possible, but I used a great resource at [GeeksForGeeks](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/);
- take all non-LIS elements to the other stack. You can optionally see whether a swap on stack-A will be more beneficial instead of a push (suppose swapping on stack-A will sort that element onto the LIS, such as in <code>2 1 3</code>);
- (*this is the fun part*): iterate over **all** elements of stack-B, looking for the least-costly-movement. What you aim for in this phase is sorting *one* element of stack-B into stack-A, with the least cost possible. 

This last phase can be a bit tricky, as it also involves one further optimization that is necessary for optimal results. Take into account the cost of rotation and reverse rotation on each, and make it so that the algorithm recognizes 5 A-rotations and 7 B-rotations to amount a total cost of 7 -- because 5 of them can be rotation on both

### That is actually quite helpful! So much so that the tears stopped flowing from my face!

I'm happy. But now, I got to go! Good luck!

### You too, Alexandre. Now, please, hang-up!

No... *you* hang-up!

### This is so silly. Didn't you have to go?

Yes, but I don't want to be the one hanging-up...! ☎️

### Well fine...*let's stay here for eternity*, then...
