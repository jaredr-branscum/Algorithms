package com.aggregate.map.data;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class HobbyReport {
    Map<String, Double> hobbyBudget = new HashMap<String, Double>();
    ArrayList<String> totalHobbies = new ArrayList<String>();

    public boolean equals(HobbyReport otherReport){
        // classic way, loop a Map
	if(!hobbyBudget.equals(otherReport.hobbyBudget)) {
        return false;
    }

    if(!totalHobbies.equals(otherReport.totalHobbies)) {
        return false;
    }
    
    return true;
    }
}
