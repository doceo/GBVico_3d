
spessore=5; //da decidere se uguale per tutte oppure no
altezza=50; //uguale per tutte le pareti
lunghezza_uno=60; //lunghezza della prima parete
lunghezza_due = 40; //lunghezza della seconda parete

// la distanza della porta deve essere considerata in  relazione all'angolo tra le pareti
altezza_porta = 20; 
larghezza_porta = 10;
distanza_porta = 15;

due_pareti_porta();

module due_pareti(){
   
    cube([lunghezza_uno, spessore, altezza]);
   rotate([0,0,90])    cube([lunghezza_uno, spessore, altezza]);
    
}


module due_pareti_porta(){
    
    difference(){
        due_pareti();
        translate([15,0,0]) cube([larghezza_porta,spessore,altezza_porta]);
    }
}