package com.aaa.ndkbuild;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

import com.aaa.jnilibrary.SignUtil;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        final TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(new JNIUtils().stringFromJNI());
        
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String sign = SignUtil.sign("432", "123");
                tv.setText(sign);
            }
        });
        
    }

}
