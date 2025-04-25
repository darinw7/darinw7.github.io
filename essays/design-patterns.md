---
layout: essay
type: essay
title: "Design Patterns within Software Engineering"
# All dates must be YYYY-MM-DD format!
date: 2025-04-24
published: true
labels:
  - Software Engineering
  - Design Patterns
---
<img src="https://github.com/user-attachments/assets/10befb6f-aea2-4ebe-886e-46d7256cf8ed"
    alt="Screen Shot"
    style="float: left; margin: 0 15px 10px 0; width: 300px;">

## Introduction
The concept of design patterns can be both challenging and rewarding at the same time. In the world of software engineering, even the most talented and skillful programmers often do not create all of their code from scratch. That's not to say that they aren't capable of doing so but rather there are better methods they can make use of to reach their end goals more efficiently. In this essay, I will go in depth about design patterns — what they are and how they have been relevant to my coding experiences so far.

<div style="clear: both;">
  <h2>Recognizing the Pattern behind Code</h2>
  <p>
    Imagine having to create a brand new software application for your company and no template is provided to you. This is where design patterns come into play, particularly for saving time and effort that could be used instead to make the program better. It essentially lays out the foundation for what we want to create by providing reusable solutions that can be used to solve common design problems. As expected however, there are also setbacks that come with this of which should not be overlooked. One of the biggest negatives is that the patterns are very generic and as a result may require a lot of changes to make it unique and suitable for the right situations.
  </p>
</div>

## My Personal Experiences with Using Design Patterns
As for design patterns that I've implemented into my source codes, a great example of this would be in the project I am currently working on with my group in ICS 314 Software Engineering class. We are currently working on creating an app called Arthub that allows users within Manoa to either showcase their art or sell them. Within it, is a profiles page in which I was tasked with creating, that includes the use of design patterns as building blocks to begin the development of the site as a whole. For example, 

**Part of my AddProfileForm component source code**:
```
const AddProfileForm: React.FC = () => {
  const { data: session, status } = useSession();
  const currentUser = session?.user?.email || '';

  const {
    register,
    handleSubmit,
    reset,
    formState: { errors },
  } = useForm<FormInputs>({
    resolver: yupResolver(AddProfileSchema) as Resolver<FormInputs>,
  });
```

## Conclusion
Imagine having to create a brand new software application for your company and no template is provided to you. This is where design patterns come into play, particularly for saving time and effort that could be used instead to make the program better. It essentially lays out the foundation for what we want to create by providing reusable solutions that can be used to solve common design problems. As expected however, there are also setbacks that come with this of which should not be overlooked. One of the biggest negatives is that the patterns are very generic and as a result may require a lot of changes to make it unique and suitable for the right situations.

