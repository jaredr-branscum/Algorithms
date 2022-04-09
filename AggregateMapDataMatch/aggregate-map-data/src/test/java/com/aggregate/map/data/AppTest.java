package com.aggregate.map.data;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import org.junit.Test;

/**
 * Unit Test File
 */
public class AppTest 
{
    @Test
    public void returnEmptyHobbyReport()
    {
        HobbyReport report = new HobbyReport();
        Map<String, HobbyProfile> emptyMap = new HashMap<String, HobbyProfile>();
        HobbyReport result = App.generateHobbyReport(emptyMap);
        assertTrue(result instanceof HobbyReport);
        assertTrue(result.equals(report));
    }

    @Test
    public void compareNonEqualReports()
    {
        HobbyReport report = new HobbyReport();
        report.totalHobbies = new ArrayList<String>();
        report.totalHobbies.add("VideoGames");
        Map<String, HobbyProfile> emptyMap = new HashMap<String, HobbyProfile>();
        HobbyReport result = App.generateHobbyReport(emptyMap);
        assertTrue(result instanceof HobbyReport);
        assertFalse(result.equals(report));
    }
}
