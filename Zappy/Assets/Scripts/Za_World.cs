﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Za_World : MonoBehaviour {

    public Vector3 rot;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        transform.Rotate(rot);
	}
}