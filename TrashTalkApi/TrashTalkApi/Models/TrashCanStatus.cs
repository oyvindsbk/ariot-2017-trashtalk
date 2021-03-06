﻿using System;

namespace TrashTalkApi.Models
{
    public class TrashCanStatus
    {
        public Guid DeviceId { get; set; }
        public DateTime Timestamp { get; set; }
        public Accelerometer Accelerometer { get; set; }
        public int Distance { get; set; }
        public Temperature Temperature { get; set; }
    }
}
