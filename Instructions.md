## Connecting Two Players

1. Create a 3rd person game

 ![](Images/2017-08-01_17-12-26.png)

2. Play as two (or more) Players

 ![](Images/2017-08-01_17-20-15.png)

3. Add more player starts

 ![](Images/2017-08-01_17-23-10.png)

4. Need to add many to avoid clash probability

## Introducing the Client-Server model

1. Launch a game standalone:

 ```
 & "C:\Program Files\UE_4.16\Engine\Binaries\Win64\UE4Editor.exe" "C:\...\Puzzler\Puzzler.uproject" -game -log
 ```
2. Just run a dedicated server:

  ```
 & "C:\Program Files\UE_4.16\Engine\Binaries\Win64\UE4Editor.exe" "C:\...\Puzzler\Puzzler.uproject" /Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap -server -log
 ```

3. Note what happens with a bad path.

4. Find you IP then launch:

 ```
 & "C:\Program Files\UE_4.16\Engine\Binaries\Win64\UE4Editor.exe" "C:\...\Puzzler\Puzzler.uproject" 192.168.1.90 -game -log
 ```

## Detecting Where The Code is Running

1. Create a StaticMesh actor.
2. Add movement logic (including mobility)
3. Only run with authority.

## Authority and Replication

1. Explain the authority and replication model.
1. Enable replication of movement.
2. Notice what happens when we only make change to client.
3. Explain the behaviour when client stands on the platform.

## Aside: Faster Build Times

1. Explain symbols, headers and linkers
2. How modules are just a DLL system.
2. Remove by process of elimination.

## Revision: Adding Vectors and Normalisation

1. Editable widget.
2. Revision of Vectors.
3. Direction and normalisation challenge.

## Revision: Vector Dot Products

1. What is a dot product.
2. Create the scheme.
3. Implement and factor.

## Creating a Simple Platform Puzzle

1. Better level layout.

 ![](Images/2017-08-02_15-41-42.png)
2. Tweak the jumping movement.

 ![](Images/2017-08-02_15-40-26.png)

## Setup a Platform Trigger

1. Create the C++ base
2. Add box component.
3. Tweak in BP child.
4. Place in the world.

## Enable Triggering Callbacks

1. Show one trigger.
2. Challenge the other.

## Activating Platforms from Triggers

1. Overview the desired behaviour
1. Create an activation int.
3. Create TArray for platforms.
4. For loop on trigger.

## When to use a GameInstance

1. Create derived class.
2. Set as game instance for project.
 ![](Images/2017-08-04_13-33-52.png)
2. If not working, restart the editor.
3. Investigate difference between init and constructor.
4. Answer: Init not in editor.

## Accessing UI Classes in C++

1. Create a widget.
2. Reference the class in Constructor.
3. Include `UMG` module. Must rebuild VS proj.
3. Ensure we have the right class in init.

## Load and Display UI in C++

1. Create a `UFUNCTION` on the GI.
2. Call it from the level BP for now.
 ![](Images/2017-08-04_14-16-33.png)
3. Print the string.
4. Create and attach to viewports

## Changing Input Modes in C++

(Steps shown in code.)

## Advanced UMG layout

1. What we want to achieve

 ![](Images/2017-08-04_18-46-05.png)
1. Using vertical boxes (and containers generally)
2. Size boxes for auto padding.
3. Create menu level.
4. Challenge for UI creation, eventual solution:

 ![](Images/2017-08-04_18-43-28.png)

## Connecting UMG to C++

1. Create a `UUserWidget` C++ class.
2. Add bind widget.
2. Reparent the BP.

 ![](Images/2017-08-04_18-54-14.png)
3. Check errors.

 ![](Images/2017-08-04_18-57-42.png)

