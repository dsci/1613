program MinimumFolge (input,output);
{ liest eine Folge von 20 integer Zahlen ein und bestimmt das Minimum}

	const 
	FELDGROESSE = 20;
	
	type
	tIndex = 1..FELDGROESSE;
	tZahlenfeld = array [tIndex] of integer;
	
	var
	Feld: tZahlenfeld;
	Minimum: integer;
	i:tIndex;
	
begin 
	{Einlesen des Feldes}
	writeln('Bitte ', FELDGROESSE, ' Zahlen eingeben!');
	for i:=1 to FELDGROESSE do
		readln(Feld[i]);
	Minimum := Feld[1];
	for i:=2 to FELDGROESSE do
		if Feld[i] < Minimum then
			Minimum := Feld[i];
	{Ausgabe des Minimums}
	writeln('Die kleinste Zahl ist ', Minimum, '.');
end.{MinimumFolge}