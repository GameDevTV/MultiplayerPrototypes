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
