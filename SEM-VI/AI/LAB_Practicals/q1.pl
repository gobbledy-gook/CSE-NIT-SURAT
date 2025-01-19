indication("fever").
indication("rash").
indication("headache").
indication("runny_nose").
indication("conjunctivitis").
indication("cough").
indication("body_ache").
indication("chills").
indication("sore_threat").
indication("sneezing").

docter("D1", "flu").
docter("D_02", "Common Cold").
docter("D1", "Chicken Pox").
doctor("D_04", "Measles").

patient("P_01", "Raj", address("SVNIT", "Surat", "395007"), [treatment(docter_code, disease)]).
patient("P_02", "Aryan", address("VNIT", "Nagpur", "315007"), [treatment(docter_code, disease)]).
patient("P_03", "Mohan", address("NITD", "Delhi", "195007"), [treatment(docter_code, disease)]).
patient("P_04", "Atal", address("IITD", "Delhi", "495007"), [treatment(docter_code, disease)]).

indication("Raj", ["fever", "headache", "body_ache", "conjunctivitis", "chills","sore_throat", "runny_nose", "cough"]).
indication("Aryan", ["fever", "headache", "body_ache", "conjunctivitis", "chills","sore_throat", "runny_nose", "cough"]).
indication("Atal", ["fever", "headache", "body_ache", "conjunctivitis", "chills", "rash"]).

disease("flu", "fever").
disease("flu", "headache").
disease("flu", "body_ache").
disease("flu", "conjunctivitis").
disease("flu", "chills").
disease("flu", "sore_throat").
disease("flu", "runny_nose").
disease("flu", "cough").    

symptom(Name,illness) :-
    indication(Name, ListOfIllness),
    member(illness, ListOfIllness).

treatment(doctor_code, disease):-
    doctor(doctor_code, disease).   

hypothesis(name,disease):-
    symptom(Name, "fever"),
    symptom(Name, "headache"),
    symptom(Name, "body_ache"),
    symptom(Name, "conjunctivitis"),
    symptom(Name, "chills"),
    symptom(Name, "sore_throat"),
    symptom(Name, "runny_nose"),
    symptom(Name, "cough").
    
