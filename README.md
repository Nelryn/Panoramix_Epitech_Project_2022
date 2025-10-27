# Panoramix Epitech Project 2022

**Panoramix** is a multithreaded simulation written in **C** that models the teamwork between the druid Panoramix and the indomitable villagers of Gaul.
Each villager fights Roman soldiers as long as there’s potion in the cauldron — and calls the druid to refill it when it’s empty.

This project explores synchronization, concurrency, and thread safety using **mutexes** and **semaphores** in C language.

---

## 🧠 Concept

It’s 50 BC.
The Romans occupy almost all of Gaul... except one small village! The druid **Panoramix** brews the magic potion that gives the villagers their legendary strength.

In this simulation:

* Several **villagers** act in parallel, each in their own **thread**.
* The **druid** is also a thread that refills the potion cauldron when called.
* Proper synchronization ensures no two villagers drink simultaneously from an empty pot and that the druid refills only when needed.

---

## ⚙️ Usage

### 🧰 Compilation

```bash
make
```

### ▶️ Run the program

```bash
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

### ❓ Parameters

| Argument       | Description                                   | Constraint |
| -------------- | --------------------------------------------- | ---------- |
| `nb_villagers` | Number of villagers (threads)                 | > 0        |
| `pot_size`     | Maximum number of potion servings per refill  | > 0        |
| `nb_fights`    | Number of fights each villager will engage in | > 0        |
| `nb_refills`   | Number of times the druid can refill the pot  | > 0        |

---

## 🧵 Threads and Synchronization

| Entity        | Role            | Thread Behavior                                                                               |
| ------------- | --------------- | --------------------------------------------------------------------------------------------- |
| **Druid**     | Refills the pot | Waits for calls from villagers; refills using semaphores until out of ingredients             |
| **Villagers** | Fight Romans    | Drink potion before each fight; if empty, call druid and wait; stop after all fights are done |

The program must:

* Use **mutexes** to protect shared resources (like the potion pot).
* Use **semaphores** for thread synchronization.
* Stop gracefully once all villagers are done and the druid has no potion left.

---

## 🧾 Expected Output Messages

### Villagers

```
Villager <id>: Going into battle!
Villager <id>: I need a drink... I see <servings> servings left.
Villager <id>: Hey Pano wake up! We need more potion.
Villager <id>: Take that roman scum! Only <fights> left.
Villager <id>: I'm going to sleep now.
```

### Druid

```
Druid: I'm ready... but sleepy...
Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make <refills> more refills after this one.
Druid: I'm out of viscum. I'm going back to... zZz
```

---

## 🔒 Exit Codes

| Code | Meaning                            |
| ---- | ---------------------------------- |
| `0`  | Successful execution               |
| `84` | Invalid arguments or runtime error |

---

## 📂 Project Structure

```
Panoramix_Epitech_Project_2022/
├── src/              # Source files (.c)
├── include/          # Header files (.h)
├── Makefile          # Build system
├── tests/            # Unit or integration tests
└── README.md         # Project documentation
```
