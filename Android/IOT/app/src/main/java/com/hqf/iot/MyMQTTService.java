package com.hqf.iot;

import android.app.Service;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;
import android.widget.ImageView;
import android.widget.Toast;

import com.google.gson.Gson;

import org.eclipse.paho.android.service.MqttAndroidClient;
import org.eclipse.paho.client.mqttv3.IMqttActionListener;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.IMqttToken;
import org.eclipse.paho.client.mqttv3.MqttCallbackExtended;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

public class MyMQTTService extends Service {
    MqttAndroidClient mqttAndroidClient;
    private static final String TAG = "MyMQTTService";
    final String serverUri = "tcp://192.168.0.106:1883";
    String clientId = "hqf";
    final String subscriptionTopic = "/Subscription/Topic";
    final String publishTopic = "/Publish/Topic";//推送主题
    //final String publishMessage = "Hello World!";//推送信息
    public MyMQTTService() {
    }

    public class MyBinder extends Binder {
        public MyMQTTService getService() {
            return MyMQTTService.this;
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        //throw new UnsupportedOperationException("Not yet implemented");
        return new MyBinder();
    }

    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    public void init(MqttCallbackExtended mqttCallbackExtended) {
        //新建client实例
        clientId = clientId + System.currentTimeMillis();
        mqttAndroidClient = new MqttAndroidClient(getApplicationContext(), serverUri, clientId);
        //设置回调函数
        mqttAndroidClient.setCallback(mqttCallbackExtended);
        //连接设置，是否重连，是否清理session
        MqttConnectOptions mqttConnectOptions = new MqttConnectOptions();
        mqttConnectOptions.setAutomaticReconnect(true);
        mqttConnectOptions.setCleanSession(false);

        try {
            //连接mqtt服务器
            mqttAndroidClient.connect(mqttConnectOptions, null, new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    makeToast("连接成功");
                    //订阅topic
                    subscribeToTopic();
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    makeToast("连接失败");
                }
            });
        } catch (MqttException ex) {
            ex.printStackTrace();
        }
    }
    public void subscribeToTopic() {
        try {
            //开始订阅
            mqttAndroidClient.subscribe(subscriptionTopic, 0, null, new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    makeToast("成功订阅到" + subscriptionTopic);
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    makeToast("订阅失败" + subscriptionTopic);
                }
            });

        } catch (MqttException ex) {
            ex.printStackTrace();
        }
    }
    /*推送消息*/
    public void publishMessage(String publicMessage){

        try {
            MqttMessage message = new MqttMessage();
            message.setPayload(publicMessage.getBytes());
            mqttAndroidClient.publish(publishTopic, message);
            //addToHistory("Message Published");
            if(!mqttAndroidClient.isConnected()){
                //addToHistory(mqttAndroidClient.getBufferedMessageCount() + " messages in buffer.");
                makeToast("推送消息失败");
            }
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    private void makeToast(String str) {
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }
}