# Decision Tree - DSA Assignment

## Introduction

**Decision Tree** is an assignment in the **Data structure and Algorithms** (*DSA*) Course of UET (***University of Engineering and Technology***).  
The lecturer of this course: **BSc. Pham Dinh Tuan**.

## Usage

### Input

The basic input is **Data** which have 4 attributes called `<att1>, <att2>, <att3>, <att4>` and 1 label which can be L (*left*), R (*right*) và B (*balance*).  
Input data is split into three different parts:  
- The **training part** is file [`train.txt`]() which is being used to train the decision tree.  
- The **public test** is file [`valid.txt`]() which is being used to test the prediction of the tree. All the data in **valid** have their label, so we can check if our tree had predicted the right label of each data.  
- The **private test** is file [`private.txt`]() which is being used to test the prediction of the tree and the answer is given to our lecturer for the assignment's score. Note that all the data in **private** don't have their label!  

### Output

The basic output is **Label** of one prediction based on 4 attributes in the basic data. Our goal is to build a decision tree that can predict the **Label** of a given **Data** and improve the prediction accuracy of the tree.  
Output data is split into two parts:
- The **output** is file [`outputFromTerminal`]() which has the best output prediction accuracy of the tree that we had tested since the project started.  
- The **private answer** is file [`result.txt`]() which contains the answer for the **private test**.  
- The **saved tree** is file [`savedData.txt`]() which contains the data that is exported from a tree and can be imported to build a tree. We store the best model of the decision tree in this file!

### Tree details

A decision tree is being used to predict labels based on 4 given attributes. It can be L or R or B. There are two things we need to know when we are building or training a decision tree. They are:  
- `max depth` is the **highest level of the tree**.  
- `min size` is the **minimum size that a node in the tree can contain**.  

When evaluating a tree, we notice two things (or three in this project):
- **The accuracy of trainData** - this is the accuracy of the prediction when we used a tree to predict the label of the trainData (`train.txt`).  
- **The accuracy of validData** - this is the accuracy of the prediction when we used a tree to predict the label of the validData (`valid.txt`).  
- **The accuracy of testData** - Just like the two things above, but testData is new data that has been created for this project.

### How to run it?

Download the source file (as .zip). Extract to a folder and open `cmd` in that folder.   
To run the program just paste this line to `cmd` and hit `Enter`:
```cmd
g++ -std=c++17 AdaBoost.cpp Stump.cpp BitMask.cpp Console.cpp CostCalc.cpp Data.cpp DecisionNode.cpp Node.cpp SplitData.cpp TerminalNode.cpp TestGenerator.cpp Tree.cpp RandomForest.cpp Client.cpp -o Client
```
After hitting `Enter`, it creates a new file called `Client.exe`. You can run it by double click the file or simply paste this line to `cmd` and hit `Enter` again:
```cmd
.\Client.exe 
```
If you don't want to see the output in `cmd`, you can use this line: 
```cmd
.\Client.exe > outputFromTerminal.txt
```
After hitting `Enter`, it creates a new file called `outputFromTerminal.txt` containing the output in a txt file.

### Cmd UI

## Updates

### Update 1 - Design API

Create several basic files:  
- [`Client.cpp`]() is the file contains main function. In the future, it become the GUI to use the program.  
- [`Data.h`]() and `struct Data`. This is the basic data and basic unit of the tree.
- [`Node.h`]() and `struct Node`. A node of a tree and some function to calculate the Gini index.
- [`TestGenerator.h`]() this is a library that is designed exclusively for this project. Generate testData.
- [`Tree.h`]() and `struct tree`. Basic struct tree. 

### Update 2 - Completed some bacsic struct.

In this update, we completed the API and make a new function to calculate the `Entropy Index`.
- `struct Data` is completed.
- `giniIndex` caculate function is completed.
- Some split data into two group functions are completed.
- `entropyIndex` calculate function is completed.

After this update, the project will be bigger and we'll need to organize the file and structure more clearly.

### Update 3 - Finished `split data` + `bit mask` + `cost calc`

So in this update, we split the file into multiple header files. They are:
- `splitData.h` contains `namespace splitData`. This namespace contains functions that split data into two groups based on attributes.  
- `bitMask.h` is the header that contains functions to check if the bit in the given index of a number is 1.
- `costCalc.h` is the header contains functions to caculate `giniIndex` and `entropyIndex`.

### Update 4 - Completed buildTree and printTree

In this update, we had successfully built a decision tree and printed it out in the cmd terminal. Also, fixed some bugs about memory and debugger.  

>One thing is this update is so big that because we found trouble when coding with only header file (`.h`) but not including and splitting it to two files `.cpp` and `.h`. So we have to split it out and organize the project again. Finally, the project is very clear and there is a lot of file in the source folder xD.  

After this update, we need to create the predict function and we can start calculate the accuracy of the tree.

### Update 5 - Predict and future improve

In this update, we completed the predict function and started to predict the label of validData.  

Records:

| MAX DEPTH | MIN SIZE | COMPARISON | COMBINATION | ATTRIBUTE | 
| --------- | -------- | ---------- | ----------- | --------- |
|     2     |  1, 2, 3 | 74.1935    | 74.1935     | 64.5161   |
|     3     |  1, 2, 3 | 75.2688    | 75.2688     | 62.3656   |
|     4     |  1, 2, 3 | 77.4194    | 75.2688     | 63.4409   |
|     5     |  1, 2, 3 | 79.5699    | 77.4194     | 63.4409   |
|     6     |  1, 2, 3 | 78.4946    | 78.4946     | 77.4194   |
|     7     |  1, 2    | 77.4194    | 78.4946     | 70.9677   |
|     7     |     3    | 77.4194    | 76.3441     | 70.9677   |

So because the prediction result is low and we are not satisfied with that. So my teammate has done some research and found that we could improve the tree by adding [`Random forest`](). You can see more about this in that link.

### Update 6 - Random forest

`Random forest` is a forest that contains a lot of decision trees in it. So what makes it improve our prediction result?   

>So the first thing that we notice is the label **'B'** is the most difficult prediction. And luckily `Random forest` is good to against this trouble. By randomly generating some boost trap data with have more label **'B'** in it and then build a decision tree based on that dataset. By repeating that process, we have created a forest that can predict the label **'B'** better.

But the more we build a new tree, the more slowly it is. So we have to limit the size of the forest down to 100 trees. 

```
Best Accuracy = 79.5699% | Method: Comparision; Min size = {1, 2, 3}, Max depth = 5
```
By boosting the label **'B'** and randomly creating several trees, we have created some very best models in the upcoming update.

### Update 7 - Upgrade random forest and fixed some bugs

In this update, we notice that the way we build random forests is not the best option. So, we have to upgrade it in two ways:  
- Build the forest by trying `max depth` and `min size` (apply to all trees in the forest) to find the best model which has the best accuracy when predicting the `trainData`.
- Build the tree by trying `max depth` and `min size` to find the best tree which has the best accuracy when predicting the `trainData` or `validData` and repeat that process to make the forest.

By doing like that, we have created some best model which has a stunning result:
```
Best Accuracy = 87.0968% (valid test) | 86% (new test)
```
Also, in this update, we have created two new functions for the tree which are `import()` and `export()`. By using them, we can store our best model to file and keep it safe.  

### Update 8 - AdaBoost

In this update, we try a new way to classify the label. It's `AdaBoost`. Both Random Forest and AdaBoost algorithm is based on the creation of Forest of trees.  

Three ideas behind `AdaBoost` are
- `AdaBoost` combines a lot of "weak learners" to make classifications. The weak learners are almost always stumps (trees with one node and two leaves). 

>Random forest makes use of multiple full-size decision trees or multiple decision trees having different depths. These decision trees make use of multiple variables to do the final classification of a data point. On the other hand, AdaBoost makes use of what is called decision stumps. Decision stumps are decision trees with one node and two leaves. AdaBoost makes use of multiple decision stumps with each decision stump built on just one variable or feature. 


- Some stumps get more say in the classification than others.
 
>In Random forest, the training data is sampled based on the bagging technique. The bagging technique is a data sampling technique that decreases the variance in the prediction by generating additional data for training from the dataset using combinations with repetitions to produce multi-sets of the original data. In AdaBoost, the training data used for training subsequent decision stumps have few data samples assigned higher weights based on miss-classification of those data set in the previous decision stump. 
- Each stamp is made by taking the previous stump's mistakes into account. 

>So that in the forest of stumps made in AdaBoost, the ordering in which decision stumps are created is important. Unlike in Random forest, each decision tree is made independently of other trees. The ordering in which decision trees are created is not important at all


The prediction for label **'L'** and **'R'** are pretty good.
Although we expect AdaBoost would be more efficient than Random Forest according to the theory, the prediction for the label **'B'** is really bad. 
```
Best Accuracy = 82.7957%
```
Best forest of stumps
| Stump  | Attribute | Compare Value |   Method   | Significance | Left Label | Right Label|
| -------| --------- | ------------- | ---------- | ------------ | ---------- | ---------- |
| 1      | 3         | 3             | COMPARISON | 0.0367956    | L          | R          |
| 2      | 1         | 3             | COMPARISON | 0.0258067    | R          | L          |
| 3      | 0         | 1             | COMPARISON | 0.0154041    | R          | L          |
| 4      | 0         | 1             | COMPARISON | 0.073466     | R          | L          |
| 5      | 2         | 3             | COMPARISON | 0.11714      | R          | R          |


## Issues

We are not creating a list of Known Issues because of the limited time.  
But if you found a bug or have a new idea for this project, you can contact us (by mail).

## Support

You can ask for help in:
- Support email 1: 20020001@vnu.edu.vn
- Support email 2: phamgialinhlx@gmail.com

## Authors

This project is being developed by:
- [**Bá Lương**](https://github.com/20020001-UET)
- [**Gia Linh**](https://github.com/phamgialinhlx)

## Credits

Thanks to third-party open-source projects, contributors, and all the people who have contributed ideas, patches, bugs reports, feature requests, donations, and help me to develop this project.

Last but not least, thanks to our lecturer - **Pham Dinh Tuan** who gave us this problem and resource to research and develop this project! 