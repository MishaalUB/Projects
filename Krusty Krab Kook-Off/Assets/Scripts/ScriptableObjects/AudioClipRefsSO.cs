using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu()]
public class AudioClipRefsSO : ScriptableObject
{
    public AudioClip[] chop;                    // Use same 
    public AudioClip[] deliveryFail;            // Done
    public AudioClip[] deliverySuccess;         
    public AudioClip[] footstep;                // In process
    public AudioClip[] objectDrop;              
    public AudioClip[] objectPickup;            
    public AudioClip stoveSizzle;               // Use same
    public AudioClip[] trash;                   // Use same
    public AudioClip[] warning;                 
}
