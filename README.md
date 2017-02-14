# helium6bSim

Geant4 simulation package and analysis codes for Helium 6b experiment. The simulation code is based on the musrSim
flavor developed by physicists at PSI for muon spin rotation experiment at LEM beam line.

To run the simulation, you need to first install Geant4 with versions at least v4.10.2. 
Please get the Geant4 source from 

http://geant4.web.cern.ch/geant4/support/download.shtml

and install it according to the instructions given here 

http://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/InstallationGuide/html/ch02.html

To download the helium6bSim simulation package, under your work folder, 

```
git clone https://github.com/kimsiang/Helium6b
```

Then create 2 folders for installation and build purpose

```
cd Helium6b
mkdir helium6bSim-install
mkdir helium6bSim-build
```

Now you are ready to use cmake to create a Makefile

```
cd helium6bSim-build
cmake -DCMAKE_INSTALL_PREFIX=../helium6bSim-install ../helium6bSim
```

Now you can build and install the code

```
make; make install
```

Now copy over the required files and create a folder to hold the root files

```
cd ../helium6bSim-install
cp ../helium6bSim/101.mac ../helium6bSim/SolenoidFieldMap.txt .
mkdir data
```

To execute the simulation, simply

```
./bin/helium6bSim 101.mac
```

`101.mac` is the geant4 macro you can use to change the geometry, EM fields and particle initial parameters.
