JC = javac
R = java
SUPER = muhammedogz_interface/*.java
SUB = muhammedogz_src/*.java
JFlags = 
Classes = 

muo:
	$(JC) $(JFlags) $(SUPER) $(SUB) Test.java
	$(R) Test

javadoc:
	javadoc muhammedogz_interface/*.java muhammedogz_src/*.java -d javadoc

clean:
	rm muhammedogz_interface/*.class muhammedogz_src/*.class *.class javadoc/ -r

	