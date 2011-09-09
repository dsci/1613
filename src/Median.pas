program Median (input,output);
{ bestimmt den Median einer einzulesenden Buchstabenfolge aus 
  mindestens zwei verschiedenen Buchstaben }

	type
	tBuchstabe = 'a' .. 'z';
	tNatZahl = 0..maxint;
	tFeld = array [tBuchstabe] of boolean;
	
	var
	vorhanden: tFeld;
	gesamt,
	i,
	MedianPos: tNatZahl;
	Buchstabe: tBuchstabe;
	Zeichen: char;
	
begin
	
	{Eingabe anfordern}
	writeln('Geben Sie eine Buchstabenfolge ein.');
	writeln('Eingabeende durch ein anderes Zeichen.');
	
	{Initialisierung buchstaben vorhanden array und fundzahl}
	for Buchstabe :='a' to 'z' do
		vorhanden[Buchstabe] := false;
	gesamt := 0;
	
	{Einlesen und MArkierung setzen}
	read(Zeichen);
	while (Zeichen >= 'a') and (Zeichen <= 'z') do
	begin
		if not vorhanden[Zeichen] then
		begin
			vorhanden[Zeichen] := true;
			gesamt := gesamt + 1;
		end;
		read(Zeichen)
	end;
	writeln;
	
	{Alle Buchstaben und Marken ausgeben}
	for Buchstabe := 'a' to 'z' do
		write(Buchstabe);
	writeln;
	for Buchstabe := 'a' to 'z' do	
	begin
		if(vorhanden[Buchstabe]) then
			write('*')
		else
			write(' ');
	end;
	writeln;
	
	{Median suchen}
	MedianPos := (gesamt + 1) div 2;
	Buchstabe := 'a';
	i := 0;
	repeat
		if vorhanden[Buchstabe] then 
			i:=i+1;
		Buchstabe := succ(Buchstabe);
	until i = MedianPos;
	writeln('der Median ist: ', pred(Buchstabe), ' .');
end.{Median}