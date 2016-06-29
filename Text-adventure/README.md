

To load game: type in full filename, including extension.

Sample game GWO.txt 

To write your adventure, save your text file in the same folder as the .exe

At the end of every chapter, you can give a choice of up to three different choice-dependent destinations 
don't forget to write what the player will read about the choices before this code!

The code is as follows. a '/' to show that it is code, followed by 'c' for choices 
or 'E' for end.
if you chose choices, you must say how many choices there are: 'b' for 2 and 'c' for three.
(The amount of choices can be increased at code level by adding another case to the appropiate switch)
once this has been done, add the destination chapter numbers, with each being followed
by a '/'. all this should be done without gaps.
Examples-
to make  choice 1 lead to chapter 56, while choice 2 leads to chapter 3:
/cb56/2/
player dies,  so game over:
/E
chapter choice 1 leads to 56, 2 to 45, 3 to 4:
/cc56/45/4/ 

IMPORTANT- currently the first 'chapter' is 0, and it counts up from there. 
IMPORTANT- don't forget to regularly start a newline so that your story displays well on console!


the code for the object needed should be written before the choice code. 
the object line starts with'/', then each object effect starts with an 'o'

Then the following rules apply:

If you want a choice to **give** an object to the player, put the choice number followed by 
'g', followed by the object number. If you want a choice to only work if the player has an object,
the g is replaced by a u. 
You can make a choice need multiple objects, but to allow choice be accesable via either one object or another has not been coded in.

 NOTE: This was all dwritten a while ago, and I was planning on writing a cleaner coded version which eliminates all the quirks of the
 current system, but currently this is on hold.
