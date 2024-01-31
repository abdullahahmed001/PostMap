# Social-Media-Query-Program
So, you have been given the task of writing a program that let’s you query the
social media posts of social media users. The data for this program will be stored
in STL Map’s and MultiMap’s after being read from CSV files.
To do this, there will be two files:
• SMUsers.csv: This file will contain users of the social media company where
you are working.
• SMUserPosts.csv: This file will contain posts from the users identified in
the previous, SMUsers.csv file

1.1 Requirement #1
Create a class called SMUser (with it’s own .cpp and .hpp files):
• User ID
• User First Name
• User Last Name
• Date of Membership (use your previously written date class)




Create a class called SMUserPost (with it’s own .cpp and .hpp files):
• User ID
• Date of the post (use your previously written date class)
• Time of the post. This should be a structure named PostTime defined in
your SMUserPost class:
– Hour (an integer using 24-hour format)
– Minute (an integer)
– Second (an integer)
• The post’s text
All attributes must be private and all accessors and mutators for these attributes
made public. Data validation in the mutators must throw a C-String error and
include:
• Strings cannot be blank
• Numbers cannot be zero
• Dates must be valid
1.2 Requirement #2
In your main(), create a menu as shown below:
1. Display all Users
2. Display a Specific User
3. Display all Posts
4. Display Posts from a Specific User
5. Exit the program

   
1.3 Requirement #3
When your main() function is invoked:
• Read the SMUsers.csv file into a Map of SMUser pointers with the key for
that map being the User ID in the SMUser class. If the file doesn’t exist,
display an error message and end the program. If the user already exists in
the map, save that user’s details in a simple text file named UserErrors.txt
with some error text so the development team can fix those posts later and
DO NOT add it to the Map (skip it). Also, if any of the numeric values in the
record are invalid (using try/catch blocks while doing conversions), display
that error in the same file and skip this user.

• Read the SMUserPosts.csv file into a Multi-Map of SMUserPost pointers. If
the file doesn’t exist, display an error message and end the program. Before
adding a post to this Multi-Map, make sure that the user the post belongs to
exists in the SMUser Map. If it does not, write that post to a simple output
file named PostErrors.txt with some error text so the development team
can fix those posts later and DO NOT add it to the Multi-Map (skip it).
Also, if any of the numeric values in the record are invalid (using try/catch
blocks while doing conversions), display that error in the same file and skip
this post.



1.4 Requirement #4
When the user selects option #1, in a range-based for loop, print the user ID, User
Name (both), Date of membership (using your Date classes operator<< overload
function) and total number of posts which the user has (from the Multi-Map) in
a nicely formatted report (using iomanip) and go back to the main menu.


1.5 Requirement #5
When the user select option #2:
1. Ask the user to type an SMUser ID. If that ID does not exist in the SMUser
map, display an error message and go back to the menu
2. If the user does exist in the SMUser map, print the same information for that
user as you did for all users when option #1 was selected from the menu
3. Go back to the main menu
   
1.6 Requirement #6
When the user selects option #3, in a range-based for loop, print the user ID, date
of (using your Date’s overloaded operator<< function), time of and the text of
the post in a nicely formatted report (using iomanip).

1.7 Requirement #7
When the user selects option #4:
1. Ask the user to type an SMUser ID. If that ID does not exist in the SMUser
map, display an error message and go back to the menu
2. If the user does exist in the SMUser Map, print the Userid and name of the
user, the total number of posts the user has in the SMUserPost Multi-Map
3. Next, using the equal range function, print all of the posts from the multi-
map for the user ID input by the user under the user details in a nicely
formatted report (using iomanip). If there are no posts for that user, just
print ”No Posts Found” for that user
4. Go back to the menu

1.8 Requirement #8
When the user selects option #5:
• Iterate through the Multi-Map using a non-range based for loop and delete
each SMUserPost pointer
• Iterate through the Map using a non-range based for loop and delete each
SMUser pointer
• Clear both the Map and the Multi-Map
• Open the Posterrors.txt file and display the errors to the user to remind them
that there are problems with the csv file.
• Open the UserErrors.txt file and display the errors to the user to remind
them that there are problems with the csv file.
• Print a nice farewell message that the program is ending


Data to be used
All data will be provided by files attached to this project.
Description of the SMUser.csv data file:
• User ID (a String)
• User First Name (a String)
• User Last Name (a String)
• Date of Membership (year (integer), month (integer), day (integer))
Description of the SMUserPosts.csv data file:
• User ID (a String)
• Date of the post (year (integer), month (integer), day (integer))
• Time of the post.
– Hour (an integer using 24-hour format)
– Minute (an integer)
– Second (an integer)
• The post’s text (a String)
