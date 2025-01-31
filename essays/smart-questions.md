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
In the field of software enginnering, communicating with others is certainly one of the core aspects besides actually creating code. With that, comes asking questions when challenges arise, or something is too confusing or difficult to understand. However, one of the most overlooked part is that its not just about looking for the answer - but instead asking the right questions. As Eric Raymond's essay, *How To Ask Questions The Smart Way* discusses, creating questions that are clear and precise allow others to respond with information that is more useful and informative.

## Analyzing a Smart Question
Example: [Why is processing a sorted array faster than processing an unsorted array?](https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array)

This is an example of a well thought out question that follows the rules created by Raymond. The following characteristics make it an great example:

- **Expresses Question Clearly**: The user expressed the question clearly so that others know that they are explicity asking for the reason why sorted arrays are processed faster than non-sorted arrays.
- **Proof of Effort**: The user has put in effort to solving the problem before asking for help as evidenced by them including their C++ and Java files that they used to test the theory with.

Q: Why is processing a sorted array faster than processing an unsorted array?

**C++ Code provided by user:**:
```
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
**Java code provided by user:**
```
import java.util.Arrays;
import java.util.Random;

public class Main
{
    public static void main(String[] args)
    {
        // Generate data
        int arraySize = 32768;
        int data[] = new int[arraySize];

        Random rnd = new Random(0);
        for (int c = 0; c < arraySize; ++c)
            data[c] = rnd.nextInt() % 256;

        // !!! With this, the next loop runs faster
        Arrays.sort(data);

        // Test
        long start = System.nanoTime();
        long sum = 0;
        for (int i = 0; i < 100000; ++i)
        {
            for (int c = 0; c < arraySize; ++c)
            {   // Primary loop.
                if (data[c] >= 128)
                    sum += data[c];
            }
        }

        System.out.println((System.nanoTime() - start) / 1000000000.0);
        System.out.println("sum = " + sum);
    }
}
```

## Analyzing a Not-So-Smart Question

Example: [How do I declare and initialize an array in Java?](https://stackoverflow.com/questions/1200621/how-do-i-declare-and-initialize-an-array-in-java>)

In comparison to the smart question, this one lacks all of the principles outlined by Raymond:
- **No Proof of Effort**: The user only posts the question that they have without showing whether or not they put any effort into doing research on it before posting the question.
- **Basic & Generic**: This is a basic question that can be answered by looking in the Java documentation or even from watching a quick tutorial.

This question is not a very good question whatsover, despite it having 31 responses and a total of 5.9 million views. In fact, this post wasted a lot of people's time when the user could have just done research on it rather than be lazy, because of how simple a topic it is and the amount of information that there certainly is on the web about it. 

```
Q: How do I declare and initialize an array in Java?

How do I declare and initialize an array in Java?
```

## Answering Smart Questions Is Just as Important as Asking Them
While a large part of my essay is centered around asking Smart questions, it is also true the other way around. When providing answers to other people's questions, it is essential to explain the process clearly, and let them know if something doesn't look or sound right so that they can go and look it over again for possible errors. Also by completing this part successfully, the entire StackOverflow community can reap the benefits by learning from each other all at the same time.


## Conclusion

Software engineering is quite a challenging topic to learn especially when things are challenging and unclear, which is why asking smart questions can be the difference between success and failure. The concept of being able to communicate effectively with others is a necessary skill to have in the field, and actually benefits everyone who is involed. Whether it is about asking questions or even answering them, a similar rule holds. It is about doing the best that we can to better everyone's experiences and gain knowledge together as a large group. All in all, asking smart questions seems to be of lesser significance, but is actually just as important as creating good code.

*Used ChatGPT only for grammar purposes*
