using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rot : MonoBehaviour {

    public Quaternion Q;
	// Use this for initialization
	void Start () {
        Q = new Quaternion(1, 1, 0, 1);
        transform.rotation = Q;
    }
	
	// Update is called once per frame
	void Update () {
        transform.rotation = Q;
        Q.w = Q.w < -0.98f ? 1 : Q.w - 0.01f;
    }
}
