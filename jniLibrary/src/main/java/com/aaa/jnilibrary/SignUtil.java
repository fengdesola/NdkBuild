package com.aaa.jnilibrary;


public class SignUtil {
    static {
        System.loadLibrary("sign-lib");
    }

    public static native String sign(String a, String b);
}
