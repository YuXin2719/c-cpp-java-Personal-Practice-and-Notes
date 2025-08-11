package com.easyjava.enums;

public enum DateTimePatternEnum {
    YYYY_MM_DD("YYYY-MM-DD"),
    HH_MM_SS("HH:mm:ss"),
    YYYY_MM_DD_HH_MM_SS("YYYY-MM-dd HH:mm:ss");

    private String pattern;

    DateTimePatternEnum(String pattern) {
        this.pattern = pattern;
    }

    public String getPattern() {
        return pattern;
    }
}
