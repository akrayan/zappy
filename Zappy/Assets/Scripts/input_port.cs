using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class input_port : MonoBehaviour {
    public string port;
    void Start()
    {
      var input = gameObject.GetComponent<InputField>();
      var se = new InputField.SubmitEvent();
      se.AddListener(SubmitName);
      input.onEndEdit = se;
    }

    public void SubmitName(string arg0)
    {
      port = arg0;
      Debug.Log(arg0);
    }
    public string sendPort()
    {
        return port;
    }
}
