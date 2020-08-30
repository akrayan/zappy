using System;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;


public class Game_info : MonoBehaviour {

    public string Ip;
    public int Port;

    public void InputIP(InputField Input_ip)
    {
        Ip = Input_ip.text;
        Debug.Log(Port);
    }
    public void InputPort(InputField Input_port)
    {
        Port = int.Parse(Input_port.text);
        Debug.Log(Port);
    }
    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}
}
