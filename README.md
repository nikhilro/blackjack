# blackjack

```
make # makes the executable
make run # also runs it
make test # runs the test suite
```

## Design Choices

Since in the game of blackjack everyone is playing against the dealer, it seemed
natural to use the `Observer` patter with dealer being the subject and players 
observers. Next is the game object itself, which becomes controller in the spirit
of `MVC`. 

More high level things: `Non virtual interface` (NVI) which says all your public methods should be concrete. It's been key in the past to code extensibality since the class retains control of the interface and ensuring pre and post conditions are met. `Abstract Base Classes` (ABC) which says all base classes should be abstract. It's nice because it forces you to extract out common logic between classes. 

The other high level thing I focused on was simplicity. What's the simplest way to run the tests? What's the simplest way to store cards? 

#### Things that went well and things I wish I did more of

Most of the SOLID is achieved indicative of good OOP design. Single-responsiblity principle is sorely violated; for example, the `Dealer` is responsible for maintaining the deck, maintaining the hand state (what everyone has) and performing other dealer functions. I choose this tradeoff because code size and # of files explodes the closer one tries to follow that. Open-closed principle is held because public interface for all classes are concrete. Liskov Substitution Principle is held because of abstract base classes existing and specialization in derived classes. Interface segregation principle which is mostly "code to an interface"; again, this is `NVI`. Dependency Inversion principle is followed because all concrete entities build on abstractions `ABC`.

Since simplicity was the focus so no `Card` object is created. The `Hand` simple stores a pair of chars with one of them being

The testing rig works but I didn't get to add any tests before the deadline. 

C++ was chosen because I had previously done a command line project in C++ so felt confident in that. Less bugs because type safety among other things.

For the most part, I used smart pointers; so, there shouldn't be memory leaks; I didn't get to rigoursly test though.

The error handling is not amazing. Ideally, there would be a sanitizer class for taking in inputs in all places. That could have been used for adding commands like help etc. too. Right now, either the user enters everything perfecting or unexpected behaviour.

Ending on a positive note, streams are used everywhere and passed dowm from main to the objects so it's trivial to add graphics or other formatting feature functionality to it.



