import { useEffect, useState } from "react";
import socket from "../services/socket";
import ParkingSlot from "../components/ParkingSlot";
import StatusCard from "../components/StatusCard";

export default function Dashboard() {
  const [vagas, setVagas] = useState([]);

  useEffect(() => {
    socket.on("update_vagas", (data) => {
      setVagas(data);
    });

    return () => {
      socket.off("update_vagas");
    };
  }, []);

  return (
    <div className="dashboard-container">
      <h1>RafaPark IoT</h1>

      <div className="status-container">
        <StatusCard label="Vagas Livres" value={vagas.filter(v => !v.ocupada).length} />
        <StatusCard label="Ocupadas" value={vagas.filter(v => v.ocupada).length} />
        <StatusCard label="Total" value={vagas.length} />
      </div>

      <div className="parking-grid">
        {vagas.map((vaga) => (
          <ParkingSlot key={vaga.id_vaga} data={vaga} />
        ))}
      </div>
    </div>
  );
}
