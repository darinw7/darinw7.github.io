---
layout: essay
type: essay
title: "Smart Questions, Good Answers"
# All dates must be YYYY-MM-DD format!
date: 2025-01-30
published: true
labels:
  - StackOverflow
---

![Screen Shot 2025-01-30 at 2 36 31 PM](https://github.com/user-attachments/assets/584bea64-0ff7-4325-80dd-aa8b8c003de6)


## Introduction - Importance of Asking Smart Questions
In the field of software enginnering, communicating with others is certainly one of the core aspects besides actually creating code. With that, comes asking questions when challenges arise, or something is too confusing or difficult to understand. However, one of the most overlooked part is that its not just about looking for the answer - but instead asking the right questions. Creating questions that are clear and precise allow others to respond with information that is more useful and informative.

## Analyzing a Smart Question
Example: [Why is processing a sorted array faster than processing an unsorted array?](https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array)

This is an example of a well thought out question that follows the rules created by Raymond. The following characteristics make it an great example:

- **Expresses Question Clearly**: The user expressed the question clearly so that others know that they are explicity asking for the reason why sorted arrays are processed faster than non-sorted arrays.
- **Proof of Effort**: The user has put in effort to solving the problem before asking for help as evidenced by them including their C++ and Java files that they used to test the theory with.

```
Q: Why is processing a sorted array faster than processing an unsorted array?

#include <algorithm>
#include <ctime>
#include <iostream>

int main()
{
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;

    // !!! With this, the next loop runs faster.
    std::sort(data, data + arraySize);

    // Test
    clock_t start = clock();
    long long sum = 0;
    for (unsigned i = 0; i < 100000; ++i)
    {
        for (unsigned c = 0; c < arraySize; ++c)
        {   // Primary loop.
            if (data[c] >= 128)
                sum += data[c];
        }
    }

    double elapsedTime = static_cast<double>(clock()-start) / CLOCKS_PER_SEC;

    std::cout << elapsedTime << '\n';
    std::cout << "sum = " << sum << '\n';
}
```

While the heading of his question could be better, it does convey what he’s trying to figure out. Usually something as brief as “python date of previous month” is what other users would enter in as search terms on Google, making it easily found. Another good thing about the question is that it’s not just a question. The asker shows what he or she has done and that he or she has put in some effort to answer the question. And while it may not be as important as the question itself, the asker shows courtesy, which does increase the chance of getting an answer.

```
A: datetime and the datetime.timedelta classes are your friend.

1. find today
2. use that to find the first day of this month.
3. use timedelta to backup a single day, to the last day of the previous month.
4. print the YYYYMM string you're looking for.

Like this:

 >>> import datetime
 >>> today = datetime.date.today()
 >>> first = datetime.date(day=1, month=today.month, year=today.year)
 >>> lastMonth = first - datetime.timedelta(days=1)
 >>> print lastMonth.strftime("%Y%m")
 201202
 >>>

```

## Analyzing a Not-So-Smart Question

Example: [How do I declare and initialize an array in Java?](https://stackoverflow.com/questions/1200621/how-do-i-declare-and-initialize-an-array-in-java>)

In comparison to the smart question, this one lacks all of the principles from Eric Raymond's essay, *How To Ask Questions The Smart Way* :
- **No Proof of Effort**: The user only posts the question that they have without showing whether or not they put any effort into doing research on it before posting the question.
- **Basic & Generic**: This is a basic question that can be answered by looking in the Java documentation or even from watching a quick tutorial.

This question is not a very good question whatsover, despite it having 31 responses and a total of 5.9 million views. In fact, this post wasted a lot of people's time when the user could have just done research on it rather than be lazy, because of how simple a topic it is and the amount of information that there certainly is on the web about it. 

```
Q: How do I declare and initialize an array in Java?

How do I declare and initialize an array in Java?
```

## Conclusion

When we rely on others’ generosity and expertise to provide answers to our questions, it should hold that the question we ask should be one that leads to efficient and effective help that not only benefits us, but also the people we ask and others who might ask the same question in the future. Thus, if you have a question… make it a smart one! Asking questions may not always get you the best answer, but asking them in a way that will make others want to answer them will increase the success of finding a good solution and make it a positive experience on all sides.
